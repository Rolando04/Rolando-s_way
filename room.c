#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

roomInfo* createRooms(FILE* fileIn){
    int count = 0;
    char line[275];
    fgets(line, sizeof(line), fileIn);
    while(fgets(line,sizeof(line),fileIn)!= NULL){
        count++;
    }
    rewind(fileIn);
    roomInfo *DataRecords = ((roomInfo*)malloc((count) * (sizeof(roomInfo))));
    return DataRecords;
}
int fillRecords(roomInfo* r, FILE* fileIn){
    int numRecordsUsed = 0;
    char roomId[5],assetTag[7],serialNum[13], line[275];

    fgets(line,sizeof(line), fileIn);
    
    while(fgets(line, sizeof(line),fileIn)!= NULL){
        sscanf(line,"%[^,],%[^,],%[^,]",roomId,assetTag,serialNum);
        strcpy(r[numRecordsUsed].roomId, roomId);
        strcpy(r[numRecordsUsed].tvAsset,serialNum);
        strcpy(r[numRecordsUsed].tvSerial,serialNum);
        numRecordsUsed++;
    }
    rewind(fileIn);
    return numRecordsUsed;
}
void searchRoom(char roomID[], roomInfo* r, int size){
    for(int i = 0; i < size; i++){
        if(strcmp(roomID, r[i].roomId) == 0){
            printf("This room contains tv with asset tag %s, its serial is %s\n",r[i].tvAsset, r[i].tvSerial);
            break;
        }
    }
}

void searchAsset(char assetID[], roomInfo* r, int size){
    for(int i = 0; i < size; i++){
        if(strcmp(r[i].tvAsset,assetID) == 0){
            printf("This asset tag is in room %s, its serial number is %s\n", r[i].roomId, r[i].tvSerial);
            break;
        }
    }
}

void printRoom(roomInfo* r, int size){
    for(int i = 0;i < size; i++){
        printf("Room %s contains tv with asset tag: %s. The serial for that tv is %s\n",r[i].roomId,r[i].tvAsset,r[i].tvSerial);
    }
}

void printMenu(void){
    printf("\n\n----Search Menu----\n");
    printf("1. Search Specific Room\n");
    printf("2. Search by Asset Tag\n");
    printf("3. Print All Rooms\n");
    printf("4. Quit Search\n");
}
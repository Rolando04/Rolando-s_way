#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

int main(int argc, char argv[]){
    int selection = -1;
    char roomNum[5],assetTag[7];
    if(argc != 2){
        printf("Please insert a CSV file in the command line.\n");
        return -1;
    }
    printf("Opening %s...\n", argv[1]);
    FILE* fileIn = fopen(argv[1],"r");
    if(fileIn == NULL){
        printf("ERROR: Could not open file and end the program\n");
        return -1;
    }
    roomInfo* rooms = createRooms(fileIn);
    int numOfRooms = fillRecords(rooms,fileIn);
    fclose(fileIn);
    printf("Number of rooms in csv file: %d\n",numOfRooms);

    while(1){
        printMenu();
        scanf("%d", &selection);
        if(selection == 1){
            printf("Please enter a room number: ");
            scanf("%s", roomNum);
            printf("Searching by Room Number.\n");
            searchRoom(roomNum,rooms,numOfRooms);
        }
        else if(selection == 2){
            printf("Please enter a room number: ");
            scanf("%s", assetTag);
            printf("Searching by Asset Tag\n");
            searchAsset(assetTag,rooms,numOfRooms);
        }
        else if(selection == 3){
            printf("Printing all rooms\n");
            printRoom(rooms, numOfRooms);
        }
        else if(selection == 4){
            printf("Thank you!!\n");
            break;
        }
        else{
            printf("Please input a Valid choice\n");
        }

    }
    return -1;
}

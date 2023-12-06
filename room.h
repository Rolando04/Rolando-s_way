#ifndef ROOM_H
#define ROOM_H

typedef struct roomInfo_struct{
char roomId[5];
char tvAsset[7];
char tvSerial[13];
}roomInfo;

roomInfo* createRooms(FILE* fileIn);
int fillRecords(roomInfo* r, FILE* fileIn);
void searchRoom(char roomID[], roomInfo* r, int size);
void searchAsset(char assetID[], roomInfo* r, int size);
void printRoom(roomInfo* r, int size);
void printMenu(void);
#endif
#ifndef _tagManager
#define _tagManager

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getTagSize(FILE* fileToRead, int sizeStartOffset);
char* getTagBody(FILE* fileToRead, int tagSize);
char* getFrameDataByFrameId(char* frameID, char* tagBody, int tagBodySize, FILE* fileToRead);
int getFramePosition(char FrameID[], char tag[], int tagBodySize);
char* getFrameData(FILE* fileToRead, int framePosition, int frameSize);

#define HEADER_SIZE 10
#define FRAME_SIZE_OFFSET 4

#endif

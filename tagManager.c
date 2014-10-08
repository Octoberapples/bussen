#include "tagManager.h"

int getTagSize(FILE* fileToRead, int sizeStartOffset){
  char temp[4];
  fseek(fileToRead, sizeStartOffset, SEEK_SET);
  fread(temp, 1, 4, fileToRead);

  int tagSizeByteOne, tagSizeByteTwo, tagSizeByteThree, tagSizeByteFour;
  tagSizeByteOne = (int)(temp[0] & 127) << 21;
  tagSizeByteTwo = (int)(temp[1] & 127) << 14;
  tagSizeByteThree = (int)(temp[2] & 127) << 7;
  tagSizeByteFour = (int)(temp[3] & 127);
  int size = tagSizeByteOne | tagSizeByteTwo | tagSizeByteThree | tagSizeByteFour;

  return size;
}

char* getTagBody(FILE* fileToRead, int tagSize){
  char* tag = malloc(tagSize);
  fseek(fileToRead, 10, SEEK_SET);
  fread(tag, sizeof(char), tagSize, fileToRead);
  return tag;
}

char* getFrameDataByFrameId(char* frameID, char* tagBody, int tagBodySize, FILE* fileToRead){

  char* frameData = NULL;
  int frameSize = 0;
  int framePosition = getFramePosition(frameID, tagBody, tagBodySize);
  if(framePosition != -1){
    frameSize = getTagSize(fileToRead, framePosition + FRAME_SIZE_OFFSET);
    frameData = getFrameData(fileToRead, framePosition, frameSize);
  }
  return frameData;
}

int getFramePosition(char frameId[], char tagBody[], int tagBodySize){
  int bodyIndex = 0;
  int idIndex = 0;
  int substringHit;

  while (bodyIndex < tagBodySize) {
    while (tagBody[bodyIndex] != frameId[0] && tagBody[bodyIndex] != '\0'){
      bodyIndex++;
    }

    substringHit = bodyIndex;

    while (tagBody[bodyIndex] == frameId[idIndex] && tagBody[bodyIndex] != '\0' && frameId[idIndex] != '\0') {
      bodyIndex++;
      idIndex++;
    }

    if (frameId[idIndex] == '\0'){
      return substringHit + HEADER_SIZE;
    }

    bodyIndex = substringHit + 1;
    idIndex = 0;
  }
  return -1;
}

char* getFrameData(FILE* fileToRead, int framePosition, int frameSize){
  char* frameData = malloc(frameSize);
  fseek(fileToRead, framePosition + HEADER_SIZE + 1, SEEK_SET);
  fread(frameData, sizeof(char), frameSize, fileToRead);
  return frameData;
}

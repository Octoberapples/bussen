#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "tagManager.h"

struct Mp3File;
typedef struct Mp3File* Mp3File;

void validateProgramArguments(int argc, char* argv[]);
void sortMp3Files(char* path);
void sortFile(char* path, char* fileName);
FILE* getFileStream(char* path, char* fileName);
void collectFileData(Mp3File fileData, FILE* fileToRead, char* fileNameData);
void copyFile(Mp3File fileData, FILE* sourceFile, char* sourcePath);

#include "main.h"

struct Mp3File{
  char* fileName;
  char* newFileName;
  char* artist;
  char* album;
};

int main(int argc, char* argv[])
{
  validateProgramArguments(argc, argv);

  char* path = argv[1];
  sortMp3Files(path);

  return 0;
}

void validateProgramArguments(int argc, char* argv[]){
  if(argc != 2){
    puts("Incorrect arguments!");
    puts("Argument format: main \"/pathToMp3Files/\"");
    exit(1);
  }
  int pathSlashIndex = strlen(argv[1])-1;
  if(argv[1][pathSlashIndex] != '/'){
    puts("Path needs to end with /");
    exit(1);
  }
}

void sortMp3Files(char* path){
    DIR *folder;
    struct dirent *file;

    if((folder = opendir(path)) != NULL){
        while((file = readdir(folder)) != NULL){
            if(strstr(file->d_name, ".mp3\0")){
                sortFile(path, file->d_name);
            }
        }
    }else{
        perror("Could not open folder");
	exit(1);
    }
}

void sortFile(char* path, char* fileName){

  FILE* fileToRead = getFileStream(path, fileName);

  Mp3File fileData = malloc(sizeof(*fileData));
  collectFileData(fileData, fileToRead, fileName);

  copyFile(fileData, fileToRead, path);

  free(fileData);
}

FILE* getFileStream(char* path, char* fileName){
  char pathIncludingName[strlen(path) + strlen(fileName)];
  strcpy(pathIncludingName, path);
  strcat(pathIncludingName, fileName);

  FILE* fileToRead = fopen(pathIncludingName,"rb");
  if(fileToRead == NULL){
    puts("Could not open file");
    exit(1);
  }
  return fileToRead;
}

void collectFileData(Mp3File fileData, FILE* fileToRead, char* fileNameData){

  int tagBodySize = getTagSize(fileToRead, 6);
  char* tagBody = malloc(tagBodySize);
  tagBody = getTagBody(fileToRead, tagBodySize);

  char* newFileNameData = getFrameDataByFrameId("TIT2", tagBody, tagBodySize, fileToRead);
  char* artistData = getFrameDataByFrameId("TPE1", tagBody, tagBodySize, fileToRead);
  char* albumData = getFrameDataByFrameId("TALB", tagBody, tagBodySize, fileToRead);

  fileData->fileName = fileNameData;
  fileData->newFileName = newFileNameData;
  fileData->artist = artistData;
  fileData->album = albumData;

  free(tagBody);
}

void printPathIterative(char* path){
  for(int i = 0; i < strlen(path); i++){
    printf("%c", path[i]);
  }
  puts("");
}

void printPathRecursive(char* path, int position){
  if(position == strlen(path)){
    puts("");
    return;
  }
  printf("%c", path[position]);
  printPathRecursive(path, ++position);
}

void copyFile(Mp3File fileData, FILE* sourceFile, char* sourcePath){

  int artistLength = 0;
  if(fileData->artist != NULL){
    artistLength = strlen(fileData->artist);
  }
  int albumLength = 0;
  if(fileData->album != NULL){
    albumLength = strlen(fileData->album);
  }

  fseek(sourceFile, 0, SEEK_SET);
  char targetPath[strlen(sourcePath) + strlen(fileData->newFileName) + artistLength + albumLength + 6];
  strcpy(targetPath, sourcePath);
  
  if(fileData->artist != NULL){
    strcat(targetPath, fileData->artist);
    strcat(targetPath, "/");
    mkdir(targetPath, 0755);
  }

  if(fileData->album != NULL){
    strcat(targetPath, fileData->album);
    strcat(targetPath, "/");
    mkdir(targetPath, 0755);
  }
  strcat(targetPath, fileData->newFileName);
  strcat(targetPath, ".mp3");
  //printf("%s\n", targetPath);
  printPathIterative(targetPath);
  //printPathRecursive(targetPath, 0);
  FILE* targetFile = fopen(targetPath, "wb");
  fseek(targetFile, 0, SEEK_SET);
  int character;
  while((character = getc(sourceFile)) != EOF){
    fprintf(targetFile, "%c", character);
  }
  fclose(targetFile);
  fclose(sourceFile);
}

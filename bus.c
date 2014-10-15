#include "bus.h"
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>

//eventuellt lägga till en struct för en tidtabell

struct resa;

typedef struct station {
  char *station_namn;
  struct resa *busstur;
} *Station;

typedef struct resa {
  int *tid;
  int *linje;
  struct station *bussplats1;
  struct station *bussplats2;
} *Resa;


/**int main() {
  return 0;
  }**/

//Skapa ny station, när man skapar en lista från början så är den tom men nu så innehåller station massa nman på busshållsplatser

struct station *mkStation(char *station_namn, struct resa *busstur) {
  struct station *result = malloc(sizeof(struct station));
  if (result != NULL) {
    result->station_namn = station_namn;
    result->busstur = busstur;
    return result;
  }
  return NULL;
}

//-> för members i structen . för att komma åt structen
//skapa ny länk (bågarna där bussen reser)
struct resa *mkResa(int *tid, int *linje, struct station *bussplats1, struct station *bussplats2){
  struct resa *result = malloc(sizeof(struct resa));
  if (result != NULL) {
    result->tid = tid;
    result->linje = linje;
    result->bussplats1 = bussplats1;
    result->bussplats2 = bussplats2;
    return result;
  }
  return NULL;
}

//om det första noden, sista noden och nod mitt emellan
//måste ta bort bågarna som  är kopplade till noden och sedan göra om grafen 

//har directed graph en huvudnod? För att deleta en linked list 
void deleteStation(char stationRemove, struct station *head) {
  struct station *current = head;
  struct station *previous = NULL;
  while (current != NULL) {
        if (current->station_namn == stationRemove) {
            if (previous == NULL) {
                current = current->busstur;
                free(head);
            } else {
                previous->busstur = current->busstur;
                free(current);
                current = previous->busstur;
            }
        } else {
            previous = current;
            current = current->busstur;
        }
    }    
}




char lineRead[128];

void ReadFile(FILE *fileToRead){ 
  Resa r = malloc(sizeof(struct resa)); //r i Resan ska va namnet på stationen vi hanterar
  fopen("nätverk.txt", "r");
  //här ska man ha en while eller for loop som gör antinge rekursivt eller iterativt alla stationer
  while(fgets(lineRead, 80, fileToRead) != NULL){
      
    for(int i = 0; i < 4; i++){ 
	char* tok = strtok(lineRead,",");
	switch(i) {
	case 0 : r->linje = strdup(tok);
	  break;
	case 1 : r->bussplats1 = strdup(tok);
	  break;
	case 2 : r->bussplats2 = strdup(tok);
	  break;
	case 3 : r->tid = strdup(tok);
	  break;
	  }
    }
  }
}  


//måste stänga strömmen

//clang

//ta bort en nod
//ta bort en båge
//1.find nod/båge with the element (if it exists)
//2.remove the nod/båge
//3.Reconnect the linked list
//4.Update the graph
//hitta kortaste vägen mellan två noder (Dijkstras algoritm)

//ta bort en station
//void stationDelete(Station, listXD) {
//blz remov station.yeah
//}
 













/**
typedef struct {
  int x, y;
} Point;

Point point_new(int x, int y)
{
  Point a;
  a.x = x;
  a.y = y;
  return a;
  }**/

//directed graph
//http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Graphs.html
//http://www.cs.cornell.edu/home/kleinber/networks-book/networks-book-ch02.pdf

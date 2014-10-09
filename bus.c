#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//ta bort en nod
//ta bort en båge
//hitta kortaste vägen mellan två noder (Dijkstras algoritm)

 













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

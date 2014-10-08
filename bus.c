#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct resa;
//De kallar på sig själv

typedef struct station {
  char *station_namn;
  struct resa *travel;
} *Station;

typedef struct resa {
  int *tid;
  int *linje;
  struct station *bussplats1;
  struct station *bussplats2;
} *Resa;

int main() {
  return 0;
}

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

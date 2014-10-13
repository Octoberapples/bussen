#indef _bus
#define _bus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resa;

typedef struct station;

typedef struct resa;

struct station *mkStation(char *station_namn, struct resa *busstur);

struct resa *mkResa(int *tid, int *linje, struct station *bussplats1, struct station *bussplats2);

#endif

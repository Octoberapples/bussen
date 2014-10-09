#include <stdio.h>
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




char awesome[128];

void resa(FILE* filetoread){
  Resa r = malloc(sizeof(struct resa));
  fopen("filetoread", "r");
  while(fgets(awesome, 80, filetoread) != NULL){
      
    for(int i = 0; i < 4; i++){ 
	char* tok = strtok(awesome,",");
	switch(i) {
	case 0 : r->linje = strdup(tok);
	case 1 : {
	  r->bussplats1 = strdup(tok)};
	case 2 : {r->bussplats2 = strdup(tok)};
	case 3 :{r->tid = strdup(tok)};
	  }
    }
  }
  return 0;
}
  

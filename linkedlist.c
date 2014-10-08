#include <stdio.h>
#include <stdlib.h>
 struct link {
    int value;
    struct link *next;
  };
 

struct list {
  struct link *first;
  struct link *last;
};

typedef struct list *List;

//skapa en ny lista
struct list *mkList() {
  struct list *result = malloc(sizeof(struct list));
  if (result != NULL) {
    result->first = NULL;
    result->last = NULL;
    return result;
  }
  //sätta felflaggor
  return NULL;
    }
//skapa en ny länk
 struct link *mkLink(int value, struct link *next){
  struct link *result = malloc(sizeof(struct link));
  if (result != NULL) {
    result->value = value;
    result->next = next;
    return result;
  }
  //sätta felflaggor
  return NULL;
}
//Listans längd
unsigned int length(List list) {
  unsigned int size = 0;
  struct link *cursor  = list->first;
  while  (cursor != NULL) { 
    ++ size;
    cursor  = cursor->next;
  }
  return size;
}

//Är listan tom?
int empty(List list) {
  return list->first == NULL;
}
void inject(struct link *link, int value) {
  link->next = mkLink(value, link->next);
}


//Insättning; Lägg till i början, lägg till i slutet & lägg till vid index i
void prepend(List list, int value) {
  list->first = mkLink(value, list->first);
  if (list->last == NULL) {
    list->last = list->first;
  }
  return;
}

//insättning
void insert(List list, int value, int index) {
  if (index == 0){
    prepend(list,value);
    return;
}
  struct link *cursor = list->first;
  while(cursor){
    if(index-- == 1) inject(cursor,value);
    cursor = cursor->next;
    
  }
}


void append(List list, int value) {
  if (list->last == NULL){
  list->last = list->first  = mkLink(value, NULL);
} else {
  list->last = list->last->next = mkLink(value, NULL);
 }
}

int *first(List list) { 
  if  (empty(list)) {
    return NULL;
  } else  {
    return  &(list->first->value);
  }
}

int *last(List list) {
  if (empty(list)) {
    return NULL;
  } else {
    return &(list->last->value);
  }
}
  /*  int *get(List list, int index) {
    if  (index == 0) return first(list);
    if (index == length(list)) return last(list);
    } */

  int *get(List list, int index) {
    struct link *cursor = list->first;
    while (cursor && index > 0 )  {
      if (index-- ==  0) return &(cursor->value);
      cursor = cursor->next;
    }
    return NULL;
}

/**
   Napisati program koji ucitava n prirodnih brojeva, smesta ih u jenostruko povezanu listu,
   uvecava svaki element liste za 1 i stampa sadrzaj liste.
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} TList;

void print_list(TList *list){
  while(list != NULL){
    printf("%d ", list->value);
    list = list->next;
  }
}

void add_el(TList **list, int el){
  TList *new=(TList*)malloc(sizeof(TList));
  new->value = el;
  new->next = NULL;
  if (*list==NULL)
    *list=new;
  else{
    TList* tmp;
    for(tmp=*list; tmp->next != NULL; tmp=tmp->next) ;
    tmp->next = new;
  }
}

void inc_value(TList **list){
  TList *t=*list;
  while(t != NULL){
    t->value++;
    t = t->next;
  }
}

int main(){
  TList *head, *new;
  int n;
  head = NULL;
  printf("Unesite broj elemenata liste: ");
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    int tmp;
    scanf("%d",&tmp);
    add_el(&head,tmp);
  }
  inc_value(&head);
  print_list(head);
  return 0;

}

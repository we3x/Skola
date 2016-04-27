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

void create_list(TList **head, int *n){
  printf("Uneti broj elemenata liste: ");
  scanf("%d",n);
  fflush(stdin);
  *head = NULL;
  TList *pom = *head;
  for(int i=0; i<*n; i++){
    int el;
    TList *tmp;
    tmp = (TList*)malloc(sizeof(TList));
    scanf("%d",&el);
    tmp->value = el;
    tmp->next = NULL;
    pom->next = tmp;
    pom = pom->next;
    free(tmp);
  }
}

void print_list(TList *list){
  while(list != NULL){
    printf("%d ", list->value);
    list = list->next;
  }
}

int main(){
  TList *head;
  int n;
  create_list(&head, &n);
  print_list(head);
  return 0;

}

/**
   Napisati program koji ucitava znakove i smesta ih u jednostruko povezanu
   listu sve dok korisnik ne unese ".", stanoa sadrzaj liste, kao i broj
   elemenata u listi.
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  char ch;
  struct list *next;
}TList;

void add_el(TList **list, char el){
  TList *new=(TList*)malloc(sizeof(TList));
  new->ch = el;
  new->next = NULL;
  if (*list==NULL)
    *list=new;
  else{
    TList* tmp;
    for(tmp=*list; tmp->next != NULL; tmp=tmp->next) ;
    tmp->next = new;
  }
}

void print_list(TList *list){
  while(list != NULL){
    printf("%c ", list->ch);
    list = list->next;
  }
}

int main(){
  TList *head;
  head = NULL;
  char ch;
  do{
    scanf("%c",&ch);
    add_el(&head,ch);
  }while(ch != '.');
  print_list(head);
}

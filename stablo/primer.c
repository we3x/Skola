#include <stdio.h>
#include <stdlib.h>

typedef struct cvor {
  int value;
  struct cvor *levi;
  struct cvor *desni;
}BCvor;

void insert_el (BCvor *novi, BCvor **koren){
  if (*koren == NULL){
    *koren = novi;
    novi->levi = NULL;
    novi->desni = NULL;
  } else {
    if (novi->value > (*koren)->value){
      insert_el(novi, &((*koren)->desni));
    }else if (novi->value < (*koren)->value){
      insert_el(novi, &((*koren)->levi));
    }else
      return ;
  }
}

BCvor *search_el(BCvor *koren, int key){
  if (koren == NULL){
    return NULL;
  }else{
    if (koren->value < key){
      return search_el(koren->levi, key);
    }else if ( koren->value > key){
      return search_el(koren->desni, key);
    } else
      return koren;
  }
}

void print_tree(BCvor *koren){
  if (koren == NULL){
    return;
  }
  printf("%d ", koren->value);
  print_tree(koren->levi);
  print_tree(koren->desni);
}

void delete_tree(BCvor *koren){
  if( koren == NULL)
    return;
  delete_tree(koren->levi);
  delete_tree(koren->desni);
  free(koren);
}

BCvor *min_node(BCvor *koren){
  BCvor *child;
  if (koren == NULL)
    return NULL;
  child = min_node(koren->levi);
  if (child == NULL)
    return koren;
  else
    return child;
}

void delete_node(int key,BCvor **koren){
  BCvor *min, *tmp;
  if (*koren == NULL)
    return;
  if (key < (*koren)->value)
    delete_node(key, &(*koren)->levi);
  else if (key > (*koren)->value)
    delete_node(key, &(*koren)->desni);
  else {
    if (((*koren)->levi == NULL) && ((*koren)->desni == NULL)){
      free(*koren);
      *koren = NULL;
    }else if (((*koren)->levi != NULL) || ((*koren)->desni != NULL)){
      tmp = *koren;
      *koren = (*koren)->levi != NULL ? (*koren)->levi:(*koren)->desni;
      free(tmp);
    }else{
      min = min_node((*koren)->desni);
      (*koren)->value = min->value;
      delete_node(min->value, &(*koren)->desni);
    }
  }
}

int main(){
  return 0;
}

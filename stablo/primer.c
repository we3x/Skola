#include <stdio.h>

typedef struct cvor {
  int value;
  struct cvor *levi;
  struct cvor *desni;
}BCvor;

void insert_el (BCvor novi, BCvor **koren){
  if (*koren == NULL){
    *koren = novi;
    novi -> levi = NULL;
    novi -> desni = NULL;
  } else {
    if (novi -> value > *koren -> value){
      insert_el(novi, &(*koren -> desni));
    }else if (novi -> value < *koren -> value){
      insert_el(novi, &(*koren -> levi))
    }else
      return ;
  }
}

BCvor *search_el(BCvor *koren, int key){
  if (koren == NULL){
    return NULL;
  }else{
    if (koren -> value < key){
      return search_el(koren -> levi, key)
    }else if ( koren -> value > key){
      return search_el(koren -> desni, key);
    } else
      return koren;
  }
}

void print_tree(BCvor *koren){
  if (koren == NULL){
    return;
  }
  printf("%d ", koren -> value);
  print_tree(koren -> levi);
  print_tree(koren -> desni);
}

vodi delete_tree(BCvor *koren){
  if( koren == NULL)
    return;
  delete_tree(koren->levi);
  delete_tree(koren->desni);
  free(koren);
}

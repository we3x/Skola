#include <stdio.h>
#include <stdlib.h>

typedef struct cvor {
  int value;
  struct cvor *levi;
  struct cvor *desni;
}BCvor;

void delete_tree(BCvor *koren){
  if( koren == NULL)
    return;
  delete_tree(koren->levi);
  delete_tree(koren->desni);
  free(koren);
}

int sum_listova(BCvor* koren)
{
  if (koren == NULL) return 0;
  if (koren->levi == NULL && koren->desni == NULL) return koren->value;
  return sum_listova(koren->levi) + sum_listova(koren->desni);
}

int max_value(BCvor* koren)
{
  if (koren==NULL) return 0;
  if (koren->desni==NULL) return koren->value;
  return max_value(koren->desni);
}

int debth(BCvor* koren)
{
  if (koren==NULL) return 0;
  else
    { int dl=debth(koren->levi);
      int dd=debth(koren->desni);
      return 1 + (dl>dd ? dl:dd);
    }
}

void create_bTree(int n, BCvor **koren){
  if (n == 0){
    (*koren)->levi = NULL;
    (*koren)->desni = NULL;
    return;
  }
  (*koren)->value = n;
  create_bTree(n-1, &(*koren)->levi);
  create_bTree(n-1, &(*koren)->desni);

}

int main(){
  BCvor *koren, *new;
  koren = NULL;
  return 0;
}

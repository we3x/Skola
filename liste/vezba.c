#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Objekat{
    char naziv[20];
    int kap;
    int gos;
    char tip[20];
}TObjects;

typedef struct Lista{
    TObjects objekat;
    struct Lista *sl;
}TList;


void Load(FILE *fu,TList **head){
    TList *novi;
    do{
        novi=(TList*)malloc(sizeof(TList));
        novi->sl=NULL;
        if(*head==NULL)
            *head=novi;
        else{
            TList *pom;
            pom=*head;
            while(pom->sl != NULL)
                pom=pom->sl;
            pom->sl=novi;
        }
    }while(fscanf(fu,"%s %d %d %s",novi->objekat.naziv,&novi->objekat.kap,&novi->objekat.gos,novi->objekat.tip)!=EOF);
    TList *pom=*head;
    for(pom=*head;pom->sl->sl != NULL; pom=pom->sl);
    pom->sl=NULL;
}

void print_list(TList *head){
    while(head!=NULL){
        puts(head->objekat.naziv);
        head=head->sl;
    }
}

void printObjectsOnN(TList *head){
    TObjects max,min;
    TList *pom;
    max=head->objekat;
    min=max;
    pom=head;
    while(pom!=NULL){
        if (pom->objekat.gos<max.gos)
            max=pom->objekat;
        else if (pom->objekat.gos>min.gos)
            min=pom->objekat;
        pom=pom->sl;
    }
    printf("Najstariji je %s, a najmladji %s \n",max.naziv,min.naziv);
}


void printObjectsInFile(TList *head,char s[]){
    int n=0; FILE *new;
    float pr=0;
    char str[80];
    strcat(str,"kapacitet_");
    strcpy(str,s);
    strcpy(str,".txt");
    new=fopen(str,"w");
    TList *pom=head;
    while(pom!=NULL){
        if (pom->objekat.tip==s){
            pr=pr+pom->objekat.kap;
            n++;
        }
        pom=pom->sl;
    }
    pr=pr/n;
    fprintf(new,"%d",pr);
    fclose(new);
}

int getMaxPeople(TList *head, int max){
    return 0;
}

int main(){
    FILE *fu;
    char s[20];
    TList *head;
    fu=fopen("in.txt","r");
    if (fu == NULL){
        printf("Neki strasan error");
        return 1;
    }
    head=NULL;
    Load(fu,&head);
    close(fu);
    print_list(head);
    printObjectsOnN(head);
    fgets(s, 20, stdin);
    printObjectsInFile(head,s);
    return 0;
}

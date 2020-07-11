#ifndef _TREE
#define _TREE

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} Nodo, *ABin;

void insere (ABin *a, int x);
ABin fromArray (int v[], int N);
ABin removeMaior (ABin *a);
ABin removeMenor (ABin *a);
int removeElem (ABin *a, int x);

#endif

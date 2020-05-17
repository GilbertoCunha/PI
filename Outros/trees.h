#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int valor;
  struct nodo *esq;
  struct nodo *dir;
} Nodo, *ABin;

ABin newABin (int x, ABin e, ABin d) {
  ABin r = malloc (sizeof (Nodo));
  r->valor = x;
  r->esq = e;
  r->dir = d;

  return r;
}

ABin fromArray (int v[], int N) {
  ABin r, e, d;
  if (N==0) r = NULL;
  else {
    int m = N/2;
    e = fromArray (v, m);
    d = fromArray (v+m+1, N-m-1);
    r = newABin (v[m], e, d);
  }

  return r;
}

ABin insereR (ABin a, int x) {
  if (a == NULL) {
    a = malloc (sizeof (Nodo));
    a->valor = x;
    a->esq = a->dir = NULL;
  }
  else if (a->valor > x) a->esq = insereR (a->esq, x);
       else a->dir = insereR (a->dir, x);

  return a;
}

void insere (ABin *a, int x) {
  while (*a != NULL)
    if ((*a)->valor > x) a = &((*a)->esq);
    else a = &((*a)->dir);

  *a = newABin (x, NULL, NULL);
}

ABin fromArrayP (int v[], int N) {
  ABin r = NULL;

  for (int i=0; i<N; ++i) r = insereR (r, v[i]);

  return r;
}

int procuraR (ABin a, int x) {
  int r;

  if (a == NULL) r = 0;
  else if (a->valor == x) r = 1;
  else if (a->valor > x) r = procuraR (a->esq, x);
  else r = procuraR (a->dir, x);
}

int procura (ABin a, int x) {
  int r;

  while (a != NULL && a->valor != x)
    if (a->valor > x) a = a->esq;
    else a = a->dir;

  if (a == NULL) r = 0;
  else r = 1;

  return r;
}

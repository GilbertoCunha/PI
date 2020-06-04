#include "trees.h"
#include <stdio.h>
#include <stdlib.h>

void insere (ABin *a, int x) {
  while (*a != NULL) {
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);
  }

  ABin novo = malloc (sizeof (Nodo));
  novo->valor = x;
  novo->esq = novo->dir = NULL;

  *a = novo;
}

ABin fromArray (int v[], int N) {
  ABin r = NULL;

  for (int i=0; i<N; ++i) insere (&r, v[i]);

  return r;
}

ABin removeMaior (ABin *a) {
  ABin r;

  while (*a!=NULL && (*a)->dir!=NULL) a = &((*a)->dir);

  if (*a == NULL) r = NULL;
  else {
    r = *a;
    *a = r->esq;
  }

  return r;
}

ABin removeMenor (ABin *a) {
  ABin r;

  while (*a!=NULL && (*a)->esq!=NULL) a = &((*a)->esq);

  if (*a == NULL) r = NULL;
  else {
    r = *a;
    *a = r->dir;
  }

  return r;
}

int removeBT (ABin *a, int x) {
  int r;

  while (*a!=NULL && (*a)->valor!=x) {
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);
  }

  if (*a == NULL) r = 1;
  else {
    ABin tmp = removeMaior (&(*a)->esq);

    if (tmp == NULL) *a = (*a)->dir;
    else {
      tmp->dir = (*a)->dir;
      tmp->esq = (*a)->esq;
      free (*a);
      *a = tmp;
    }

    r = 0;
  }

  return r;
}

int removeBT_simple (ABin *a, int x) {
  int r;

  while (*a!=NULL && (*a)->valor!=x) {
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);
  }

  if (*a == NULL) r = 1;
  else {
    ABin tmp = removeMaior (&(*a)->esq);

    if (tmp == NULL) *a = (*a)->dir;
    else {
      (*a)->valor = tmp->valor;
      free (tmp);
    }

    r = 0;
  }

  return r;
}

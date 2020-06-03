#include <stdio.h>
#include <stdlib.h>

typedef struct dlist {
  int valor;
  struct dlist *prox, *ant;
} NodoD, *DLInt;

void inicio (DLInt *l) {
    while ((*l)!=NULL && (*l)->ant!=NULL)
      *l = (*l)->ant;
}

void fim (DLInt *l) {
    while ((*l)!=NULL && (*l)->prox!=NULL)
      *l = (*l)->prox;
}

void concat (DLInt *a, DLInt b) {
  if (*a == NULL) *a = b;
  else {
    while ((*a)->prox != NULL) a = &((*a)->prox);
    (*a)->prox = b;
    b->ant = *a;
  }
}

LInt recLInt (DLInt l) {
  LInt r;
  if (l==NULL) r = NULL;
  else {
    r = malloc (sizeof (Nodo));
    r->valor = l->valor;
    r->prox = recLInt (l->prox);
  }

  return r;
}

LInt toLInt (DLInt l) {
  LInt r;
  inicio (&l);

  r = recLInt (l);

  return r;
}

DLInt recfromLInt (LInt l, DLInt d) {
  DLInt r;
  if (l == NULL) r = NULL;
  else {
    r = malloc (sizeof (NodoD));
    r->valor = l->valor;
    r->ant = d;
    r->prox = recfromLInt (l->prox, r);
  }

  return r;
}

DLInt fromLInt (LInt l) {
  DLInt r;

  r = recfromLInt (l, NULL);

  return r;
}

void consD (DLInt *l, int x) {
  DLInt novo = malloc (sizeof (NodoD));
  novo->valor = x;

  if ((*l)==NULL) {
    novo->ant = NULL;
    novo->prox = *l;
    *l = novo;
  }
  else {
    novo->ant = NULL;
    novo->prox = *l;
    (*l)->ant = novo;
    (*l) = novo;
  }
}

DLInt DfromArray (int v[], int N) {
  int i; DLInt r = NULL;

  for (i=N-1; i>=0; --i) consD (&r, v[i]);

  return r;
}

void printDList (DLInt l) {
  if (l==NULL) printf ("\n");
  else if (l->prox == NULL) {
    printf ("%d", l->valor);
    printDList (l->prox);
  }
  else {
    printf ("%d <-> ", l->valor);
    printDList (l->prox);
  }
}

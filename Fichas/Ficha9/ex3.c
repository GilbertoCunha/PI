#include "ficha9.h"
#include <stdio.h>
#include <stdlib.h>

void ShowDLInt (DLInt a) {
  if (a == NULL) printf ("\n");
  else if (a->prox == NULL) printf ("%d", a->valor);
  else {
    printf ("%d <-> ", a->valor);
    ShowDLInt (a->prox);
  }
}

DLInt concatDL (DLInt r, DLInt b) {
  while (r != NULL && r->prox != NULL) r=r->prox;

  if (r == NULL) {
    b->ant = NULL;
    r = b;
  }
  else if (b != NULL) {
    r->prox = b;
    b->ant = r;
  }

  while (r->ant != NULL) r = r->ant;

  return r;
}

DLInt DLfromArray_rec (int v[], int N) {
  // Versão recursiva de DLfromArray
  DLInt r;
  if (N == 0) r = NULL;
  else {
    DLInt next;
    r = malloc (sizeof (struct dlista));
    r->valor = v[0];
    r->ant = NULL;
    r->prox = NULL;

    next = DLfromArray (v+1, N-1);
    r = concatDL (r, next);
  }

  return r;
}

DLInt DLfromArray (int v[], int N) {
  // Versão imperativa de DLfromArray
  DLInt r = NULL;
  DLInt prev = NULL;

  for (int i=0; i<N; ++i) {
    r = malloc (sizeof (struct dlista));
    r->valor = v[i];
    r->ant = prev;
    r->prox = NULL;
    if (prev != NULL) prev->prox = r;
    prev = r;
    if (i != N-1) r = r->prox;
  }

  while (r->ant != NULL) r = r->ant;

  return r;
}

DLInt inorderDL (ABin a) {
  DLInt r;
  if (a == NULL) r = NULL;
  else {
    DLInt esq, dir;
    r = malloc (sizeof (struct dlista));
    r->valor = a->valor;

    // Criar DLInt à esquerda e direita
    esq = inorderDL (a->esq);
    dir = inorderDL (a->dir);

    // Concatenar as listas
    r = concatDL (esq, r);
    r = concatDL (r, dir);
  }

  return r;
}

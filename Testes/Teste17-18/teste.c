#include "teste.h"
#include <stdio.h>
#include <stdlib.h>

// Parte A
int retiraNeg (int v[], int N) {
  for (int i=0; i<N;) {
    if (v[i] < 0) {
      for (int j=i; j<N-1; ++j) v[j]=v[j+1];
      --N;
    }
    else ++i;
  }
  return N;
}

int isIn (char c, char s[], int start, int end) {
  int r;

  while (start < end && s[start] != c) start++;

  if (start == end) r = 1; //Não está
  else r = 0; //Está

  return r;
}

int difConsecutivos (char s[]) {
  int r=0;
  int start=0;
  int end=0;

  while (s[end] != 0) {
    while (isIn (s[end], s, start, end)==0) ++start;
    if (end-start+1 > r) r = end-start+1;
    ++end;
  }

  return r;
}

int maximo (LInt l) {
  int r = l->valor;
  l = l->prox;

  while (l != NULL) {
    if (l->valor > r) r = l->valor;
    l = l->prox;
  }

  return r;
}

int removeAll (LInt *l, int x) {
  int r = 0;

  while (*l != NULL)
    if ((*l)->valor == x) {
      *l = (*l)->prox;
      ++r;
    }
    else l = &((*l)->prox);

  return r;
}

void ShowLInt (LInt l) {
  while (l != NULL && l->prox != NULL) {
    printf ("%d -> ", l->valor);
    l = l->prox;
  }
  if (l != NULL) printf ("%d\n", l->valor);
  else printf ("\n");
}

LInt arrayToList (int v[], int N) {
  LInt r = NULL;
  LInt *sitio = &r;

  for (int i=0; i<N; ++i) {
    *sitio = malloc (sizeof (struct slist));
    (*sitio)->valor = v[i];
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
  }

  return r;
}

// Parte B
int max (int a, int b) {
  int r;

  if (a > b) r = a;
  else r = b;

  return r;
}

int minheapOK (ABin a) {
  int r; // 1 -> Falso, 0->Verdadeiro

  if (a == NULL) r = 0;
  else if (a->esq == NULL && a->dir == NULL) r = 0;
  else if (a->esq == NULL) {
    if (a->valor < a->dir->valor) r = minheapOK (a->dir);
    else r = 1;
  }
  else if (a->dir == NULL) {
    if (a->valor < a->esq->valor) r = minheapOK (a->esq);
    else r = 1;
  }
  else {
    if (a->valor < a->esq->valor && a->valor < a->dir->valor) {
      int r_esq = minheapOK (a->esq);
      int r_dir = minheapOK (a->dir);
      r = max (r_esq, r_dir);
    }
    else r = 1;
  }

  return r;
}

int maxHeap (ABin a) {
  int r;

  if (a != NULL) {
    if (a->esq == NULL && a->dir == NULL) r = a->valor;
    else if (a->esq == NULL) r = maxHeap (a->dir);
    else if (a->dir == NULL) r = maxHeap (a->esq);
    else r = max (maxHeap (a->esq), maxHeap (a->dir));
  }

  return r;
}

int min (int a, int b) {
  int r;

  if (a < b) r = a;
  else r = b;

  return r;
}

void removeMin (ABin *a) {
  if (*a == NULL) *a = NULL;
  if ((*a)->esq == NULL && (*a)->dir == NULL) *a = NULL;
  else if ((*a)->esq == NULL) {
    (*a)->valor = (*a)->dir->valor;
    removeMin (&((*a)->dir));
  }
  else if ((*a)->dir == NULL) {
    (*a)->valor = (*a)->esq->valor;
    removeMin (&((*a)->esq));
  }
  else {
    (*a)->valor = min ((*a)->esq->valor, (*a)->dir->valor);
    if ((*a)->valor == (*a)->esq->valor) removeMin (&((*a)->esq));
    else removeMin (&((*a)->dir));
  }
}

void add (ABin *a, int x) {
  if (*a == NULL) {
    *a = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
  }
  else if ((*a)->valor > x) {
    ABin novo = malloc (sizeof (struct nodo));
    novo->valor = x;
    novo->esq = *a;
    novo->dir = NULL;
    *a = novo;
  }
  else add (&((*a)->dir), x);
}

void heapSort (int v[], int N) {
  ABin min_heap = NULL;

  for (int i=0; i<N; ++i) add (&min_heap, v[i]);

  for (int i=0; min_heap!=NULL; ++i) {
    v[i] = min_heap->valor;
    removeMin (&min_heap);
  }
}

int kMaior (int v[], int N, int k) {
  ABin min_heap = NULL;

  for (int i=0; i<N; ++i)
    if (i < k) add (&min_heap, v[i]);
    else if (v[i] > min_heap->valor) {
      removeMin (&min_heap);
      add (&min_heap, v[i]);
    }

  return min_heap->valor;
}

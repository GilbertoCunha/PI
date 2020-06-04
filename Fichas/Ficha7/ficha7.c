#include "ficha7.h"
#include <stdio.h>
#include <stdlib.h>

void ShowDLInt (DLInt l) {
  while (l != NULL) {
    printf ("%d ", l->valor);
    if (l->prox != NULL) printf ("<-> ");
    l = l->prox;
  }
  printf ("\n");
}

void ShowLInt (LInt l) {
  while (l != NULL) {
    printf ("%d ", l->valor);
    if (l->prox != NULL) printf ("-> ");
    l = l->prox;
  }
  printf ("\n");
}

void inicio (DLInt *l) {
  while ((*l) != NULL && (*l)->ant != NULL)
    l = &((*l)->ant);
}

void fim (DLInt *l) {
  while ((*l) != NULL && (*l)->prox != NULL)
    l = &((*l)->prox);
}

void concat (DLInt *a, DLInt b) {
  fim (a);
  if (a != NULL) {
    (*a)->prox = b;
    b->ant = *a;
  }
  else *a = b;
  inicio (a);
}

DLInt DfromArray (int v[], int N) {
  DLInt r = NULL;
  DLInt ant = NULL, *sitio = &r;

  for (int i=0; i<N; ++i) {
    *sitio = malloc (sizeof (struct dlist));
    (*sitio)->valor = v[i];
    (*sitio)->ant = ant;
    (*sitio)->prox = NULL;
    ant = (*sitio);
    sitio = &((*sitio)->prox);
  }

  return r;
}

LInt LfromArray (int v[], int N) {
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

LInt toLInt (DLInt l) {
  LInt r = NULL;
  LInt *sitio = &r;

  while (l != NULL) {
    *sitio = malloc (sizeof (struct slist));
    (*sitio)->valor = l->valor;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

DLInt fromLInt (LInt l) {
  DLInt r = NULL;
  DLInt ant = NULL, *sitio = &r;

  while (l != NULL) {
    *sitio = malloc (sizeof (struct dlist));
    (*sitio)->valor = l->valor;
    (*sitio)->ant = ant;
    (*sitio)->prox = NULL;
    ant = *sitio;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

LInt reverseLInt (LInt l) {
  LInt ant, cur = NULL;

  while (l != NULL) {
    ant = cur;
    cur = l;
    l = l->prox;
    cur->prox = ant;
  }

  return cur;
}

DLInt reverseDLInt (DLInt l) {
  DLInt ant, cur = NULL;

  while (l != NULL) {
    ant = cur;
    cur = l;
    l = l->prox;
    cur->prox = ant;
    cur->ant = l;
  }

  return cur;
}

void ShowQueue (Queue q) {
  while (q.front != NULL) {
    printf ("%d ", q.front->valor);
    if (q.front->prox != NULL) printf ("-> ");
    q.front = q.front->prox;
  }
  printf ("\n");
}

void initQueue (Queue *q) {
  q->front = NULL;
  q->last = NULL;
}

int isEmptyQ (Queue *q) {
  int r;

  if (q->front == NULL) r = 1;
  else r = 0;

  return r;
}

int enqueue (Queue *q, int x) {
  int r = 0;
  LInt novo = malloc (sizeof (struct slist));

  if (novo == NULL) r = 1;
  else {
    novo->valor = x;
    novo->prox = NULL;
    if (q->front == NULL) {
      q->last = novo;
      q->front = novo;
    }
    else {
      q->last->prox = novo;
      q->last = q->last->prox;
    }
  }

  return r;
}

int dequeue (Queue *q, int *x) {
  int r = 0;

  if (q->front == NULL) r = 1;
  else {
    LInt tmp = q->front;
    q->front = q->front->prox;
    *x = tmp->valor;
    free (tmp);
  }

  return r;
}

int front (Queue *q, int *x) {
  int r = 0;

  if (q->front == NULL) r = 1;
  else *x = q->front->valor;

  return r;
}

#include "ficha6.h"
#include <stdio.h>
#include <stdlib.h>

// Exercício 1

void ShowQueue (QUEUE q) {
  for (int i=0; i<q.tamanho; ++i)
    printf ("%d ", q.valores[(q.inicio + i) % MAX]);

  printf ("\n");
}

void initQueue (QUEUE *q) {
  q->inicio = 0;
  q->tamanho = 0;
}

int isEmptyQ (QUEUE *q) {
  int r;

  if (q->tamanho == 0) r = 1;
  else r = 0;

  return r;
}

int enqueue (QUEUE *q, int x) {
  int r;

  if (q->tamanho < MAX) {
    r = 0;
    int end = q->inicio + q->tamanho;
    q->valores[end % MAX] = x;
    q->tamanho++;
  }
  else r = 1;

  return r;
}

int dequeue (QUEUE *q, int *x) {
  int r;

  if (q->tamanho == 0) r = 1;
  else {
    r = 0;
    *x = q->valores[q->inicio];
    q->inicio = (q->inicio + 1) % MAX;
    q->tamanho--;
  }

  return r;
}

int front (QUEUE *q, int *x) {
  int r;

  if (q->tamanho == 0) r = 1;
  else {
    r = 0;
    *x = q->valores[q->inicio];
  }

  return r;
}

// Exercício 2
#define START_SIZE 10

void ShowDQueue (DQUEUE q) {
  for (int i=0; i<q.tamanho; ++i)
    printf ("%d ", q.valores[(q.inicio + i) % q.size]);

  printf ("\n");
}

void initDQueue (DQUEUE *q) {
  q->size = START_SIZE;
  q->inicio = 0;
  q->tamanho = 0;
  q->valores = malloc (START_SIZE * sizeof (int));
}

int isEmptyDQ (DQUEUE *q) {
  int r;

  if (q->tamanho == 0) r = 0;
  else r = 1;

  return r;
}

void enqueueDQ (DQUEUE *q, int x) {
  if (q->tamanho == q->size) {
    int *new_values = malloc (2 * q->size * sizeof (int));

    for (int i=0; i<q->tamanho; ++i)
      new_values[i] = q->valores[(q->inicio + i) % q->size];

    free (q->valores);
    q->inicio = 0;
    q->size *= 2
    q->valores = new_values;
  }

  q->valores[q->inicio + q->tamanho] = x;
  q->tamanho++;
}

int dequeueDQ (DQUEUE *q, int *x) {
  int r;

  if (q->tamanho == 0) r = 1;
  else {
    r = 0;
    *x = q->valores[q->inicio];
    q->inicio = (q->inicio + 1) % q->size;
    q->tamanho--;
  }

  return r;
}

int frontDQ (DQUEUE *q, int *x) {
  int r;

  if (q->tamanho == 0) r = 1;
  else {
    r = 0;
    *x = q->valores[q->inicio];
  }

  return r;
}

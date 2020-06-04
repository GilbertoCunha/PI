#ifndef _FICHA7
#define _FICHA7

typedef struct dlist {
  int valor;
  struct dlist *ant, *prox;
} *DLInt;

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

void ShowDLInt (DLInt l);
void ShowLInt (LInt l);
void inicio (DLInt *l);
void fim (DLInt *l);
void concat (DLInt *a, DLInt b);
DLInt DfromArray (int v[], int N);
LInt LfromArray (int v[], int N);
LInt toLInt (DLInt l);
DLInt fromLInt (LInt l);
LInt reverseLInt (LInt l);
DLInt reverseDLInt (DLInt l);

typedef struct queue {
  LInt front, last;
} Queue;

void ShowQueue (Queue q);
void initQueue (Queue *q);
int isEmptyQ (Queue *q);
int enqueue (Queue *q, int x);
int dequeue (Queue *q, int *x);
int front (Queue *q, int *x);

#endif

#ifndef _FICHA6
#define _FICHA6

#define MAX 100
typedef struct queue {
  int inicio, tamanho;
  int valores[MAX];
} QUEUE;

// Exercício 1
void ShowQueue (QUEUE q);
void initQueue (QUEUE *q);
int isEmptyQ (QUEUE *q);
int enqueue (QUEUE *q, int x);
int dequeue (QUEUE *q, int *x);
int front (QUEUE *q, int *x);

typedef struct dqueue {
  int size;
  int inicio, tamanho;
  int *valores;
} DQUEUE;

// Exercício 2
void ShowDQueue (DQUEUE q);
void initDQueue (DQUEUE *q);
int isEmptyDQ (DQUEUE *q);
void enqueueDQ (DQUEUE *q, int x);
int dequeueDQ (DQUEUE *q, int *x);
int frontDQ (DQUEUE *q, int *x);

#endif

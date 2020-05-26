#include "ficha6.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  // Exercício 1
  QUEUE q; int x;
  initQueue (&q);
  for (int i=1; i<11; ++i)
    enqueue (&q, i);
  printf ("QUEUE: ");
  ShowQueue (q);
  dequeue (&q, &x);
  printf ("QUEUE: ");
  ShowQueue (q);
  printf ("Dequeued value: %d\n", x);
  front (&q, &x);
  printf ("Front value: %d\n", x);

  printf ("\n");

  // Exercício 2
  DQUEUE dq; int y;
  initDQueue (&dq);
  for (int i=1; i<21; ++i)
    enqueueDQ (&dq, i);
  printf ("DQUEUE: ");
  ShowDQueue (dq);
  dequeueDQ (&dq, &y);
  printf ("DQUEUE: ");
  ShowDQueue (dq);
  printf ("Dequeued value: %d\n", y);
  frontDQ (&dq, &y);
  printf ("Front value: %d\n", y);

  return 0;
}

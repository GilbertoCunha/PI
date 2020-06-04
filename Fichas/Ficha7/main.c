#include "ficha7.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  int v1[5] = {0, 1, 2, 3, 4};
  int v2[5] = {-4, -3, -2, -1, 0};

  DLInt d = DfromArray (v1, 5);
  printf ("DLInt:"); ShowDLInt (d);
  LInt ld = toLInt (d);
  printf ("LInt from DLInt:"); ShowLInt (ld);

  LInt l = LfromArray (v2, 5);
  printf ("\nLInt:"); ShowLInt (l);
  DLInt dl = fromLInt (l);
  printf ("DLInt from LInt:"); ShowDLInt (dl);

  d = reverseDLInt (d);
  printf ("\nRev DLInt: "); ShowDLInt (d);
  l = reverseLInt (l);
  printf ("Rev LInt: "); ShowLInt (l);

  Queue q;
  initQueue (&q);
  for (int i=0; i<5; ++i) enqueue (&q, v1[i]);
  printf ("\nQueue: "); ShowQueue (q);
  for (int i=0; i<4; ++i) dequeue (&q, &v1[i]);
  printf ("Dequeue: "); ShowQueue (q);
  dequeue (&q, &v1[4]);
  printf ("Queue Vazia: %d\n", isEmptyQ (&q));

  return 0;
}

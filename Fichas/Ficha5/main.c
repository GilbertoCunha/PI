#include "ficha5.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  int v[10] = {-4, -12, 4, 0, 7, 16, 21, 8, -2, 10};
  printf ("Array: ");
  ShowArray (v, 10);
  printf ("iSort: ");
  iSort (v, 10);
  ShowArray (v, 10);

  int v1[10] = {-4, -12, 4, 0, 7, 16, 21, 8, -2, 10};
  printf ("Array: ");
  ShowArray (v1, 10);
  printf ("maxSort: ");
  maxSort (v1, 10);
  ShowArray (v1, 10);

  int v2[10] = {-4, -12, 4, 0, 7, 16, 21, 8, -2, 10};
  printf ("Array: ");
  ShowArray (v2, 10);
  printf ("bubbleSort: ");
  bubbleSort (v2, 10);
  ShowArray (v2, 10);

  int v3[10] = {-4, -12, 4, 0, 7, 16, 21, 8, -2, 10};
  printf ("Array: ");
  ShowArray (v3, 10);
  printf ("Fast bubbleSort: ");
  fastbubbleSort (v3, 10);
  ShowArray (v3, 10);

  return 0;
}

#include "trees.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  int v[15] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
  ABin arv1 = fromArray (v, 15);
  ABin arv2 = arv1;

  int result = iguaisAB (arv1, arv2);
  printf ("Iguais: %d\n", result);

  return 0;
}

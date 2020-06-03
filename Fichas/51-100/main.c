#include "listas.h"
// #include "trees.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  int v[7] = {1, 2, 3, 4, 5, 6, 7};
  LInt l = fromArray_L (v, 7);
  ImprimeL (l);

  LInt l_clone = cloneRev (l);

  ImprimeL (l_clone);

  // ABin arv1 = fromArray (v, 15);
  // ABin arv2 = arv1;

  // int result = iguaisAB (arv1, arv2);
  // printf ("Iguais: %d\n", result);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main () {
  int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ABin arv1 = fromArray (v, 5);
  ABin arv2 = fromArrayP (v, 5);

  return 0;
}

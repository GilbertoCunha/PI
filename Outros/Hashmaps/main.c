#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  LHASH h;
  init_lhash (&h);
  for (int i=0; i<100; ++i) add_lhash (&h, 3*pow (i, 2) + 21 - 5*SIZE);
  printf ("\n");
  printf ("Create hash:\n"); ShowLHash (h);

  for (int i=0; i<50; ++i) rem_lhash (&h, 3*pow (i, 2) + 21 - 5*SIZE);
  printf ("\nRemove from Hash:\n"); ShowLHash (h);

  return 0;
}

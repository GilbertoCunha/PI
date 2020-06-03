#include "exame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Hist h = NULL;
  inc (&h, "o"); inc (&h, "Mauro");
  inc (&h, "e"); inc (&h, "gay");
  inc (&h, "e"); inc (&h, "paneleiro");
  ShowHist (h);
  int count;
  char *mf;
  mf = remMaisFreq (&h, &count);
  ShowHist (h);
  printf ("Removed '%s' with %d ocurrences\n", mf, count);

  return 0;
}

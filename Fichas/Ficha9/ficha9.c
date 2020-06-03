#include "ficha9.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  int v[7] = {-3, -2, -1, 0, 1, 2, 3};
  LInt lista = fromArray (v, 7);
  ShowLInt (lista);

  ABin arv = fromList (lista);
  ShowABin (arv);

  DLInt dlista = DLfromArray (v, 7);
  ShowDLInt (dlista);

  return 0;
}

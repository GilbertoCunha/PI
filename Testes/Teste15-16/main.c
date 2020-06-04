#include "exame.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  int v1[3][3] = {{2, 0, -1}, {0, 3, 1}, {4, 0, 0}};
  int v2[3][3] = {{1, 0, 3}, {4, 0, 0}, {1, 0, 0}};

  Mat m1 = fromArray (3, 3, v1);
  Mat m2 = fromArray (3, 3, v2);

  printf ("Mat1:\n");
  ShowMat (m1, 3, 3);
  printf ("\nMat2:\n");
  ShowMat (m2, 3, 3);

  printf ("\nMat1 + Mat2:\n");
  addTo (&m1, m2);
  ShowMat (m1, 3, 3);

  printf ("\nMat2 Transpose:\n");
  transpose (&m2);
  ShowMat (m2, 3, 3);

  return 0;
}

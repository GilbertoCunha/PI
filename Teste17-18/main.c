#include "teste.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  printf ("Ex 1:\n");
  int v[10] = {-1, 10, 21, 4, -3, 4, -7, 0, 4, -10};
  printf ("Array: ");
  for (int i=0; i<10; ++i) printf ("%d ", v[i]);
  printf ("\nretiraNeg: ");
  int N = retiraNeg (v, 10);
  for (int i=0; i<N; ++i) printf ("%d ", v[i]);
  printf ("\n\n");

  printf ("Ex 2:\n");
  char s[21] = "aabcccaac";
  int maior_subs = difConsecutivos (s);
  printf ("String: %s\n", s);
  printf ("Maior Substring: %d caracteres\n\n", maior_subs);

  printf ("Ex 3 e 5:\n");
  LInt l = arrayToList (v, N);
  printf ("List from array: ");
  ShowLInt (l);
  int max_l = maximo (l);
  printf ("Maximo: %d\n\n", max_l);

  printf ("Ex 4:\n");
  printf ("List: ");
  ShowLInt (l);
  int removed = removeAll (&l, 4);
  printf ("removeAll 4: ");
  ShowLInt (l);
  printf ("\n");

  return 0;
}

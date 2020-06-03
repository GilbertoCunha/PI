#include "ficha4.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main () {
  char s1[6] = "Mauro";
  char s2[17] = "Xau\nMauro\nes\ngay";
  char s3[17] = "Xau Mauro es gay";
  char *s4[4] = {"O", "Mauro", "e", "gay"};

  printf ("%s tem %d minusculas\n", s1, minusculas (s1));
  printf ("%s tem %d linhas\n", s2, contalinhas (s2));
  printf ("%s tem %d palavras\n", s3, contaPal (s3));
  printf ("%s está na posição %d de %s\n", s1, procura (s1, s4, 4), s3);

  int p;
  STACK s;

  initStack (&s);
  push (&s, 1);
  ShowStack (s);
  push (&s, 2);
  push (&s, 3);
  ShowStack (s);
  pop (&s, &p);
  ShowStack (s);

  return 0;
}

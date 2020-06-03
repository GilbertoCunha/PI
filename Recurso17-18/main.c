#include "exame.h"
#include <stdio.h>

int main () {
  FILE *f;
  char texto[300];

  f = fopen ("texto.txt", "r");
  if (f != NULL) {
    fseek (f, 0, SEEK_END);
    long fsize = ftell (f);
    fseek (f, 0, SEEK_SET);
    fread (texto, 1, fsize, f);
    fclose (f);
    texto[fsize] = 0;
    printf ("Texto: %s\n", texto);
    printf ("Formatação:\n");
    formata (texto, 30);
  }

  return 0;
}

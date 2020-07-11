#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  char texto[50] = "Teste de programacao imperativa";
  pad (texto, 4, 2);
  printf ("%s\n", texto);

  return 0;
}

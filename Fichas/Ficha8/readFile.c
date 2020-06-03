#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dicionario.h"

#define SIZE 200

int main () {
  char buffer[SIZE];
  int index;
  int c;
  Dicionario dic1;

  // Inicializar variáveis
  index = 0;
  buffer[index] = '\0';
  c = 1;
  initDic (&dic1);

  // Ler do teclado e criar dicionário
  while (c != EOF) {
    c = getchar ();

    if (!isalpha (c) && c!='-' && index!=0) {
      buffer[index] = '\0';
      index = 0;
      //printf ("-->");
      //puts (buffer);
      acrescenta (&dic1, buffer);
    }
    else if (isalpha (c) || c=='-') {
      buffer[index] = c;
      index++;
    }
  }

  // Mostrar Dicionário
  showDic(dic1);

  // Calcular palavra mais freq
  int num;
  char *freq = strdup(maisFreq (dic1, &num));
  printf ("Mais freq: %s :: %d ocorrências\n", freq, num);

  return 0;
}

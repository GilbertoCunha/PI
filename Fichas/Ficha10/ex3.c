#include "ficha10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void acrescentaAlunoF (FILE *f, Aluno a) {
  long ant, pt, end_novo;
  FArv buf, novo;

  ant = 0L;
  fseek (f, 0L, SEEK_SET);
  fread (&pt, sizeof (long), 1, f);

  // Ir para a posição de escrita do novo aluno
  while (pt != 0L) {
    fseek (f, pt, SEEK_SET);
    fread (&buf, sizeof (FArv), 1, f);
    ant = pt;
    if (a.numero < buf.a.numero) pt = buf.esq;
    else if (a.numero == buf.a.numero) break;
    else pt = buf.dir;
  }

  // Escrever o novo aluno no ficheiro
  if (pt == 0L) {
    novo.a.nome = strdup (a.nome);
    novo.a.numero = a.numero;
    novo.a.nota = a.nota;
    novo.esq = novo.dir = 0L;

    fseek (f, 0L, SEEK_END);
    end_novo = ftell (f);
    fwrite (&novo, sizeof (FArv), 1, f);

    fseek (f, ant, SEEK_SET);
    if (ant == 0) fwrite (&end_novo, sizeof (long), 1, f);
    else {
      fread (&buf, sizeof (FArv), 1, f);
      if (a.numero < buf.a.numero) buf.esq = end_novo;
      else buf.dir = end_novo;
      fseek (f, ant, SEEK_SET);
      fwrite (&buf, sizeof (FArv), 1, f);
    }
  }

}

long procuraF (FILE *f, int numero) {
  long r;
  FArv buf;

  fseek (f, 0L, SEEK_SET);
  fread (&r, sizeof (long), 1, f);

  while (r != 0L) {
    fseek (f, r, SEEK_SET);
    fread (&buf, sizeof (FArv), 1, f);
    if (numero < buf.a.numero) r = buf.esq;
    else if (numero == buf.a.numero) break;
    else r = buf.dir;
  }

  return r;
}

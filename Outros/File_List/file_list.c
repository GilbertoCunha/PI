#include "file_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista acrescentaL (Lista l, char *n) {
  Lista ant, pt;
  ant = NULL; pt = l;

  while (pt != NULL && strcmp (pt->nome, n) < 0) {
    ant = pt;
    pt = pt->prox;
  }

  if (pt == NULL || strcmp (pt->nome, n) != 0) {
    Lista novo = malloc (sizeof (struct slist));
    strcpy (novo->nome, n);
    novo->prox = pt;
    if (ant == NULL) l = novo;
    else ant->prox = novo;
  }

  return l;
}

void ShowLista (Lista l) {
  while (l != NULL && l->prox != NULL) {
    printf ("%s -> ", l->nome);
    l = l->prox;
  }

  if (l != NULL) printf ("%s\n", l->nome);
}

void acrescentaF (FILE *f, char *n) {
  long ant, pt, end_novo;
  Nodo buf, novo;

  ant = 0L;
  fseek (f, 0L, SEEK_SET);
  fread (&pt, sizeof (long), 1, f);

  // Encontrar a posição a escrever no file
  while (pt != 0L) {
    fseek (f, pt, SEEK_SET);
    fread (&buf, sizeof (Nodo), 1, f);
    if (strcmp (buf.nome, n) >= 0) break;
    ant = pt; pt = buf.prox;
  }

  if (pt == 0L || strcmp (buf.nome, n) != 0) {
    // Criar novo Nodo
    strcpy (novo.nome, n);
    novo.prox = pt;

    // Escrever o novo nodo
    fseek (f, 0L, SEEK_END);
    end_novo = ftell (f);
    fwrite (&novo, sizeof (Nodo), 1, f);

    // Ligar a lista
    if (ant == 0L) {
      fseek (f, 0L, SEEK_SET);
      fwrite (&end_novo, sizeof (long), 1, f);
    }
    else {
      fseek (f, ant, SEEK_SET);
      fread (&buf, sizeof (Nodo), 1, f);
      buf.prox = end_novo;
      fseek (f, (-1) * sizeof (Nodo), SEEK_CUR);
      fwrite (&buf, sizeof (Nodo), 1, f);
    }
  }
}

void ShowFileList (FILE *f) {
  Nodo buf;
  long end;

  fseek (f, 0L, SEEK_SET);
  fread (&end, sizeof (long), 1, f);

  while (end != 0L) {
    fseek (f, end, SEEK_SET);
    fread (&buf, sizeof (Nodo), 1, f);
    printf ("%s -> ", buf.nome);
    end = buf.prox;
  }

  printf ("0L\n");
}

#include "trees.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

ABin insere (ABin a, int x) {
  if (a == NULL) {
    a = malloc (sizeof (struct nodo));
    a->valor = x;
    a->esq = a->dir = NULL;
  }
  else if (x < a->valor) a->esq = insere (a->esq, x);
  else a->dir = insere (a->dir, x);

  return a;
}

ABin fromArray (int v[], int N) {
  ABin r = NULL;

  for (int i=0; i<N; ++i) r = insere (r, v[i]);

  return r;
}

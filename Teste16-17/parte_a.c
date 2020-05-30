#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limpaEspacos (char t[]) {
  int r = 0;

  if (t[0] == 0) return 0;

  for (r=1; t[r]!=0; ++r) {
    if (isspace (t[r]) && isspace (t[r-1]))
      for (int j=r; t[j+1]!=0; ++j) t[j] = t[j+1];
    else ++r;
  }

  return r;
}

void transposta (int N, float m [N][N]) {
  for (int i=0; i<N; ++i) {
    for (int j=0; j<i; ++j) m[i][j] = m[j][i];
  }
}

LInt cloneL (LInt l) {
  LInt r;

  if (l == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct slista));
    r->valor = l->valor;
    r->prox = cloneL (l->prox);
  }

  return r;
}

int nivelV (ABin a, int n, int v[]) {
  int r;

  if (a == NULL || n == 0) r = 0;
  else if (n == 1) {
    v[0] = a->valor;
    r = 1;
  }
  else {
    r = nivelV (a->esq, n-1, v);
    r += nivelV (a->dir, n-1, v+r);
  }

  return r;
}

void removeMaiorA (ABin *a) {
  while (*a != NULL & (*a)->dir != NULL) a = &((*a)->dir);
  *a = NULL;
}

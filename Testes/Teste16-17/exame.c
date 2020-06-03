#include "exame.h"
#include <stdio.h>
#include <stdlib.h>

// Parte A
int limpaEspacos (char t[]) {
  int r = 0;

  while (t[r] != 0)
    if (t[r+1] == ' ' && t[r] == ' ')
      for (int j=0; t[r+j]!=0; ++j) t[r+j] = t[r+j+1];
    else ++r;

  return r;
}

void transposta (int N, float m[N][N]) {
  int i, j;
  for (i=0; i<N; ++i)
    for (j=0; j<i; ++j) m[i][j] = m[j][i];
}

LInt cloneL (LInt l) {
  LInt r = NULL;
  LInt *sitio = &r;

  while (l != NULL) {
    *sitio = malloc (sizeof (struct slist));
    (*sitio)->valor = l->valor;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

int nivelV (ABin a, int n, int v[]) {
  int r;

  if (a == NULL || n < 1) r = 0;
  else if (n == 1) {
    r = 1;
    v[0] = a->valor;
  }
  else {
    r = nivelV (a->esq, n-1, v);
    v[r++] = a->valor;
    r += nivelV (a->dir, n-1, v+r);
  }

  return r;
}

void removeMaiorA (ABin *a) {
  while (*a != NULL && (*a)->dir != NULL) a = &((*a)->dir);
  if (*a != NULL) {
    ABin tmp = *a;
    *a = (*a)->esq;
    free (tmp);
  }
}

// Parte B
int push (StackC *s, int x) {
  int r=0;

  if (s->sp == MAXc) {
    CList novo = malloc (sizeof (struct chunk));
    if (novo == NULL) r = 1;
    else {
      novo->vs[0] = x;
      novo->prox = s->valores;
      s->valores = novo;
      s->sp = 1;
    }
  }
  else s->valores->vs[s->sp++] = x;

  return r;
}

int pop (StackC *s, int *x) {
  int r = 0;

  if (s->valores == NULL) r = 1;
  else if (s->sp == 0) {
    CList tmp = s->valores;
    s->valores = s->valores->prox;
    free (tmp);
    s->sp = MAXc-1;
    *x = s->valores->vs[s->sp];
  }
  else *x = s->valores->vs[s->sp--];

  return r;
}

int size (StackC s) {
  int r=0;

  while (s.valores != NULL) {
    r += s.sp;
    s.valores = s.valores->prox;
    s.sp = MAXc;
  }

  return r;
}

void reverse (StackC *s) {
  int len = size (*s);
  int values[len];

  for (int i=0; i<len; ++i) pop (s, &(values[i]));
  for (int i=0; i<len; ++i) push (s, values[i]);
}

void swap (StackC *s, int n, int *value) {
  // Coloca o valor de value no n-ésimo elemento
  // Coloca o valor do n-ésimo elemento em value

  while (s->valores != NULL && s->sp < n) {
    s->valores = s->valores->prox;
    n -= s->sp;
  }

  if (s->valores != NULL) {
    int aux = *value;
    *value = s->valores->vs[s->sp-n];
    s->valores->vs[s->sp-n] = aux;
  }

}

void new_reverse (StackC *s) {
  int index, len = size (*s);
  for (int i=0; i<(len/2); ++i) {
    index = s->sp - i % MAXc;
    if (index == 0) {
      s->valores = s->valores->prox;
      s->sp = MAXc - 1;
    }
    swap (s, len-1-i, &(s->valores->vs[index]));
  }
}

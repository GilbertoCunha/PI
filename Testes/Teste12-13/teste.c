#include "teste.h"
#include <stdio.h>
#include <stdlib.h>

// Exercício 1
int take (int n, LInt *l) {
  int r = 0;

  if (n == 0) free (*l);

  while (*l != NULL && n != 1) {
    l = &((*l)->prox);
    --n; ++r;
  }

  return r;
}

// Exercício 2
int maiores (ABin a, int x) {
  int r;

  if (a == NULL) r = 0;
  else if (x >= a->valor) r = maiores (a->dir, x);
  else r = 1 + maiores (a->esq, x) + maiores (a->dir, x);

  return r;
}

// Exercício 3
int pertence (LBloco l, int x) {
  int r;
  int i = 0;

  while (l != NULL && l->valores[i++] != x)
    if (i == l->quantos) {
      i = 0;
      l = l->prox;
    }

  if (l == NULL) r = 0;
  else r = 1;

  return r;
}

// Exercício 4
LBloco fromArray (int v[], int n) {
    LBloco r = NULL;
    LBloco pt = r;

    // Preencher totalmente até pelo menos o "penúltimo bloco"
    // Garantir 50% min de preenchimento
    while (n != 0 || (n % N <= N/2 && n % N != 0 && n > N) ) {
      pt = malloc (sizeof (Bloco));
      pt->quantos = 0; pt->prox = NULL;

      for (int i=0; i<N; ++i) {
        pt->valores[pt->quantos++] = v[0];
        v = v+1;
      }

      n -= N; pt = pt->prox;
    }

    // Preencher os dois últimos blocos
    if (n != 0) {
      pt = malloc (sizeof (Bloco));
      pt->quantos = 0; pt->prox = NULL;

      for (int i=0; i<n-n/2; ++i) {
        pt->valores[pt->quantos++] = v[0];
        v = v+1; n--;
      }
      pt = pt->prox;

      pt = malloc (sizeof (Bloco));
      pt->quantos = 0; pt->prox = NULL;

      for (int i=0; i<n; ++i) {
        pt->valores[pt->quantos++] = v[0];
        v = v+1;
      }
    }

    return r;
}

void toArray (LBloco l, int r[]) {
  int num = 0;
  while (l != NULL) {
    for (int i=0; i<l->quantos; i++)
      r[num++] = l->valores[i];
    l = l->prox;
  }
}

void acrescenta (LBloco *l, int n) {
  int size = 0;
  LBloco *pt = l;

  while (*pt != NULL) {
    size += (*pt)->quantos;
    pt = &((*pt)->prox);
  }

  int *v = malloc (size * sizeof (int));
  toArray (*l, v);
  *l = fromArray (v, size);
}

#include "ficha9.h"
#include <stdio.h>
#include <stdlib.h>

void padding (int n) {
  for (int i=0; i<n; ++i) putchar('\t');
}

void ShowABinaux (ABin a, int level) {
  if (a==NULL) printf("\n");
  else {
    ShowABinaux (a->dir, level+1);
    padding (level);
    printf ("%d\n", a->valor);
    ShowABinaux (a->esq, level+1);
  }
}

void ShowABin (ABin a) {
  ShowABinaux (a, 0);
}

void ShowLInt (LInt l) {
  if (l == NULL) printf("\n");
  else if (l->prox == NULL) {
    printf ("%d\n", l->valor);
  }
  else {
    printf ("%d -> ", l->valor);
    ShowLInt (l->prox);
  }
}

LInt fromArray (int v[], int N) {
  LInt r;

  if (N == 0) r = NULL;
  else {
    r = malloc (sizeof (struct lista));
    r->valor = v[0];
    r->prox = fromArray (v+1, N-1);
  }

  return r;
}

int lengthL (LInt l) {
  int r;

  for (r=0; l!=NULL; l=l->prox) ++r;

  return r;
}

ABin fromList (LInt l) {
  ABin r;
  if (l == NULL) r = NULL;
  else if (l->prox == NULL) {
    r = malloc (sizeof (struct nodo));
    r->valor = l->valor;
    r->esq = r->dir = NULL;
  }
  else {
    // Encontrar tamanho da lista
    int m = lengthL (l)/2 - 1;
    LInt esq, mid, dir;

    // Dividir l nas listas do valor central e
    // à esquerda e direita do valor central
    esq = l;
    for (int i=0; i<m; ++i) l=l->prox;
    mid = l->prox;
    l->prox = NULL;
    dir = mid->prox;
    mid->prox = NULL;

    // Criar a árvore a partir das três listas
    r = malloc (sizeof (struct nodo));
    r->esq = fromList (esq);
    r->valor = mid->valor;
    r->dir = fromList (dir);
  }

  return r;
}

LInt concatL (LInt l1, LInt l2) {
  LInt r = l1;

  if (l1 == NULL) r = l2;
  else {
    while (l1->prox != NULL) l1 = l1->prox;
    l1->prox = l2;
  }

  return r;
}

LInt inorderL (ABin a) {
  LInt r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct lista));
    r->valor = a->valor;
    r->prox = NULL;
    r = concatL (inorderL (a->esq), r);
    r = concatL (r, inorderL (a->dir));
  }

  return r;
}

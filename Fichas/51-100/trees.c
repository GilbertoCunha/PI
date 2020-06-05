#include "trees.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

int max (int a, int b) {
  int r;

  if (a > b) r = a;
  else r = b;

  return r;
}

// 28: 10/10
int altura (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else {
    int h_esq, h_dir;
    h_esq = altura (a->esq);
    h_dir = altura (a->dir);
    r = 1 + max (h_dir, h_esq);
  }

  return r;
}

// 29: 10/10
ABin cloneAB (ABin a) {
  ABin r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct nodo));
    r->valor = a->valor;
    r->esq = cloneAB (a->esq);
    r->dir = cloneAB (a->dir);
  }

  return r;
}

// 30: 10/10
void mirror (ABin *a) {
  if (*a != NULL) {
    ABin tmp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = tmp;
    mirror (&((*a)->dir));
    mirror (&((*a)->esq));
  }
}

LInt concat (LInt a, LInt b) {
  LInt r = a;

  if (a == NULL) r = b;
  else if (b != NULL) {
    while (a->prox != NULL) a = a->prox;
    a->prox = b;
  }

  return r;
}

// 31: 10/10
void inorder (ABin a, LInt *l) {
  *l = NULL;
  if (a != NULL) {
    inorder (a->esq, l);
    while (*l != NULL) l = &((*l)->prox);
    (*l) = malloc (sizeof (struct lista));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    inorder (a->dir, &((*l)->prox));
  }
}

// 32: 10/10
void preorder (ABin a, LInt *l) {
  *l = NULL;
  if (a != NULL) {
    *l = malloc (sizeof (struct lista));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    preorder (a->esq, &((*l)->prox));
    while (*l != NULL) l = &((*l)->prox);
    preorder (a->dir, l);
  }
}

// 33: 10/10
void postorder (ABin a, LInt *l) {
  *l = NULL;
  if (a != NULL) {
    postorder (a->esq, l);
    while (*l != NULL) l = &((*l)->prox);
    postorder (a->dir, l);
    while (*l != NULL) l = &((*l)->prox);
    *l = malloc (sizeof (struct lista));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
  }
}

int min (int a, int b) {
  int r;

  if (a < b) r = a;
  else r = b;

  return r;
}

// 34: 10/10
int depth (ABin a, int x) {
  int r;

  if (a == NULL) r = -1;
  else if (a->valor == x) r = 1;
  else {
    int r_esq = depth (a->esq, x);
    int r_dir = depth (a->dir, x);

    if (r_esq == -1 && r_dir == -1) r = -1;
    else if (r_esq == -1) r = 1 + r_dir;
    else if (r_dir == -1) r = 1 + r_esq;
    else r = 1 + min (r_esq, r_dir);
  }

  return r;
}

// 35: 10/10
int freeAB (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else {
    r = 1 + freeAB (a->dir) + freeAB (a->esq);
    free (a);
  }

  return r;
}

int pruneAB_aux (ABin *a, int l, int level) {
  int r;
  if (*a == NULL) r = 0;
  else if (level <= l) {
    int r_dir, r_esq;
    r_dir = pruneAB_aux (&((*a)->dir), l, level+1);
    r_esq = pruneAB_aux (&((*a)->esq), l, level+1);
    r = r_esq + r_dir;
  }
  else {
    int r_dir, r_esq;
    r_dir = pruneAB_aux (&((*a)->dir), l, level+1);
    r_esq = pruneAB_aux (&((*a)->esq), l, level+1);

    if (level != l+1) free (a);
    else *a = NULL;

    r = 1 + r_dir + r_esq;
  }

  return r;
}

// 36: 10/10
int pruneAB (ABin *a, int l) {
  int r = pruneAB_aux (a, l, 1);
  return r;
}

// 37: 10/10
int iguaisAB (ABin a, ABin b) {
  int r;
  if (a == NULL && b == NULL) r = 1;
  else if (a == NULL || b == NULL) r = 0;
  else if (a->valor == b->valor)
    r = iguaisAB (a->esq, b->esq) && iguaisAB (a->dir, b->dir);
  else r = 0;

  return r;
}

// 38: 10/10
LInt nivelL (ABin a, int n) {
  LInt r;
  if (a == NULL) r = NULL;
  else if (n == 1) {
    r = malloc (sizeof (struct lista));
    r->valor = a->valor;
    r->prox = NULL;
  }
  else {
    LInt r_dir;
    r = nivelL (a->esq, n-1);
    r_dir = nivelL (a->dir, n-1);
    r = concat (r, r_dir);
  }

  return r;
}

// 39: 10/10
int nivelV (ABin a, int n, int v[]) {
  int r;
  if (a == NULL) r = 0;
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

// 40: 10/10
int dumpABin (ABin a, int v[], int N) {
  int r;
  if (a == NULL || N == 0) r = 0;
  else {
    r = dumpABin (a->esq, v, N);
    if (r < N) {
      v[r] = a->valor;
      ++r;
    }
    if (r < N) r += dumpABin (a->dir, v+r, N-r);
  }

  return r;
}

int somaABin (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else r = a->valor + somaABin (a->esq) + somaABin (a->dir) ;

  return r;
}

// 41: 10/10
ABin somasAcA (ABin a) {
  ABin r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct nodo));
    r->valor = somaABin (a);
    r->esq = somasAcA (a->esq);
    r->dir = somasAcA (a->dir);
  }

  return r;
}

// 42: 10/10
int contaFolhas (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else if (a->dir == NULL && a->esq == NULL) r = 1;
  else r = contaFolhas (a->esq) + contaFolhas (a->dir);

  return r;
}

// 43: 10/10
ABin cloneMirror (ABin a) {
  ABin r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct nodo));
    r->valor = a->valor;
    r->esq = cloneMirror (a->dir);
    r->dir = cloneMirror (a->esq);
  }

  return r;
}

int addOrd_rec (ABin *a, int x) {
  int r;

  if (*a == NULL) {
    *a = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
    r = 0;
  }
  else if (x < (*a)->valor) r = addOrd (&((*a)->esq), x);
  else if (x == (*a)->valor) r = 1;
  else r = addOrd (&((*a)->dir), x);

  return r;
}

// 44: 10/10
int addOrd (ABin *a, int x) {
  int r;

  while (*a != NULL && (*a)->valor != x) {
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);
  }

  if (*a == NULL) {
    r = 0;
    *a = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
  }
  else r = 1;

  return r;
}

// 45: 10/10
int lookupAB (ABin a, int x) {
  int r;

  while (a != NULL && a->valor != x) {
    if (x < a->valor) a = a->esq;
    else a = a->dir;
  }

  if (a == NULL) r = 0;
  else r = 1;

  return r;
}

// 46: 10/10
int depthOrd (ABin a, int x) {
  int r = 1;

  while (a != NULL && a->valor != x) {
    if (x < a->valor) a = a->esq;
    else a = a->dir;
    ++r;
  }

  if (a == NULL) r = -1;

  return r;
}

// 47: 10/10
int maiorAB (ABin a) {
  int r;

  while (a->dir != NULL) a = a->dir;

  r = a->valor;

  return r;
}

// 48: 10/10
void removeMaiorA (ABin *a) {
  while ((*a) != NULL && (*a)->dir != NULL)
    a = &((*a)->dir);

  if (*a != NULL) {
    ABin tmp = (*a)->esq;
    free (*a);
    *a = tmp;
  }
}

// 49: 10/10
int quantosMaiores (ABin a, int x) {
  int r;

  if (a == NULL) r = 0;
  else if (a->valor <= x) r = quantosMaiores (a->dir, x);
  else r = 1 + quantosMaiores (a->esq, x) + quantosMaiores (a->dir, x);

  return r;
}

// 50: 10/10
void listToBTree (LInt l, ABin *a) {
  while (l != NULL) {
    *a = insere (*a, l->valor);
    l = l->prox;
  }
}

int quantosMenores (ABin a, int x) {
  int r;

  if (a == NULL) r = 0;
  else if (a->valor >= x) r = quantosMenores (a->esq, x);
  else r = 1 + quantosMenores (a->esq, x) + quantosMenores (a->dir, x);

  return r;
}

// 51: 10/10
int deProcura (ABin a) {
  int r;

  if (a == NULL) r = 1;
  else {
    int menores, maiores;
    menores = quantosMenores (a->dir, a->valor);
    maiores = quantosMaiores (a->esq, a->valor);

    if (maiores != 0 && menores != 0) r = 1;
    else r = deProcura (a->esq) && deProcura (a->dir);
  }

  return r;
}

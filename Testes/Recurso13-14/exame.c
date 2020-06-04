#include "exame.h"
#include <stdio.h>
#include <stdlib.h>

int palindrome (char s[]) {
  int r, len;

  for (len=0; s[len]!=0; ++len);
  for (r=0; r<len/2 && s[r]==s[len-1-r]; ++r);

  if (r == len/2) r = 1;
  else r = 0;

  return r;
}

char *my_strlchr (char *s, char c) {
  char *r = NULL;

  for (int i=0; s[i]!=0; ++i)
    if (s[i] == c) r = &c;

  return r;
}

void insere (int nums[], int notas[], int num, int nota, int n) {
  int i, j=n;
  for (i=0; i<n && notas[i]<nota; ++i);
  while (j = i+1) {
    notas[j] = notas[j-1];
    nums[j] = nums[j-1];
  }
  notas[i] = nota;
  nums[i] = num;
}

void ordena (int nums[], int notas[], int n) {
  for (int i=0; i<n; ++i)
    insere (nums, notas, nums[i], notas[i], i);
}

int dumpL (LInt l, int v[], int N) {
  int r=0;

  for (r=0; l!=NULL && r<N; ++r) {
    v[r] = l->valor;
    l = l->prox;
  }

  return r;
}

LInt somas (LInt l) {
  LInt r = NULL;
  LInt *sitio = &r;
  int counter = 0;

  while (l != NULL) {
    counter += l->valor;
    *sitio = malloc (sizeof (struct slist));
    (*sitio)->valor = counter;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
  }
}

void remreps (LInt l) {
  while (l != NULL && l->prox != NULL)
    if (l->valor == l->prox->valor)
      l->prox = l->prox->prox;
    else l = l->prox;
}

int contaFolhas (ABin a) {
  int r;

  if (a == NULL) r = 0;
  else if (a->esq == NULL && a->dir == NULL) r = 1;
  else r = contaFolhas (a->esq) + contaFolhas (a->dir);

  return r;
}

void arrayToTab (int N, Tabuleiro *t, int board[N][N]) {
  // Converte um 2D array numa
  // lista ligada de posições
  int i, j;
  for (i=0; i<N; ++i)
    for (j=0; j<N; ++i)
      if (board[i][j] != 0) {
        *t = malloc (sizeof (Posicao));
        (*t)->x = i; (*t)->y = j;
        (*t)->prox = NULL;
        t = &((*t)->prox);
      }
}

int PosicaoOK (Tabuleiro p, Tabuleiro t) {
  // Testa se uma posição p é válida
  // Num dado tabuleiro t
  int r;

  while (t != NULL)
    if (p->x == t->x) break;
    else if (p->y == t->y) break;
    else if (p->x+p->y == t->x+t->y) break;
    else if (p->x-p->y == t->x-t->y) break;
    else t = t->prox;

  if (t == NULL) r = 1; // OK
  else r = 0; // Not OK

  return r;
}

int validSol (int N, int board[N][N]) {
  int r = 1;
  Tabuleiro aux, t = NULL;

  arrayToTab (N, &t, board);

  while (t != NULL && r == 1) {
    aux = t;
    t = t->prox;
    aux->prox = NULL;
    r = PosicaoOK (aux, t);
    free (aux);
  }

  return r;
}

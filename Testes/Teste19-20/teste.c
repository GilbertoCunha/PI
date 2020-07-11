#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica (int s[], int N) {
  int r;

  if (N == 0 || N == 1) r = 1;
  else {
    int a, b, i;
    a = s[1] / s[0]; b = s[1] % s[0];
    for (i=2; i<N; ++i)
      if (s[i]/s[i-1]!=a && s[i]%s[i-1]!=b) break;

    if (i != N) r = 0;
    else r = 1;
  }

  return r;
}

void gera (LInt *l, int N) {
  int a_0, a_1;
  a_0 = 0; a_1 = 1;
  *l = NULL;

  for (int i=0; i<N; ++i) {
    *l = malloc (sizeof (struct slist));
    (*l)->valor = a_0 + a_1;
    (*l)->prox = NULL;
    a_0 = a_1; a_1 = (*l)->valor;
    l = &((*l)->prox);
  }
}

LInt anterior (LInt l) {
  LInt r = l;

  while (r != NULL && r->prox != l)
    r = r->prox;

  return r;
}

LInt snoc (LInt l, int x) {
  LInt r = l;
  LInt *sitio = &r;

  while (*sitio != NULL) sitio = &((*sitio)->prox);
  *sitio = malloc (sizeof (struct slist));
  (*sitio)->valor = x;
  (*sitio)->prox = NULL;
}

void imprimeAux (ABin t, LInt path) {
  // path é uma lista ligada com inteiros
  // que representam o caminho percorrido
  // 0 -> esquerda e 1->direita
  if (t != NULL) {
    imprimeAux (t->esq, snoc (path, 0));
    imprimeAux (t->dir, snoc (path, 1));
    LInt pt = path;
    while (pt != NULL)
      if (pt->valor == 0) printf ("<");
      else printf ("<");
    printf ("%d\n", t->valor);
  }
}

void imprime (ABin t) {
  LInt path = NULL;
  imprimeAux (t, path);
}

int capicua (DLint l) {
  int r;

  while (l != NULL && l->front != NULL && l->last != NULL && l->last->valor == l->front->valor) {
    l->front = l->front->prox;
    l->last = l->last->ant;
  }

  if (l == NULL || (l->front == NULL && l->last == NULL)) r = 1; // Verdadeiro
  else r = 0; // Falso

  return r;
}

void addEspacos (char *texto) {
  int i;
  for (i=0; texto[i]!=0; ++i);
  for (i=i+1; i>0; --i) texto[i] = texto[i-1];
  texto[0] = ' ';
}

void pad (char *texto, int p, int N) {
  int i=0, j=0;
  char aux;

  if (p != 0) {
    while (texto[i]!=0 && texto[i]==' ') i++;
    while (texto[i]!=0 && texto[i]!=' ') i++;
    for (j=0; j<N; ++j) addEspacos (texto+i);
    pad (texto+i, p-1, N);
  }
}

int calculaQuantos (Palavras p) {
  int r;

  if (p == NULL) r = 0;
  else {
    int r_dir, r_esq;
    r_esq = calculaQuantos (p->esq);
    r_dir = calculaQuantos (p->dir);
    p->quantos = 1 + r_esq + r_dir;
    r = p->quantos;
  }

  return r;
}

int acrescenta (Palavras *e, char *p) {
  int r;

  if (*e == NULL) {
    *e = malloc (sizeof (struct nodoD));
    if (*e != NULL) { // Sucesso
      (*e)->quantos = 1;
      (*e)->raiz = strdup (p);
      (*e)->esq = (*e)->dir = NULL;
      r = 1;
    }
    else r = 0; // Insucesso
  }
  else if (strcmp ((*e)->raiz, p) == 0) r = 0;
  else {
    if (strcmp (p, (*e)->raiz) < 0)
      r = acrescenta (&((*e)->esq), p);
    else r = acrescenta (&((*e)->dir), p);
    if (r == 1) (*e)->quantos++;
  }

  return r;
}

char *atRank (Palavras p, int k) {
  char *r;

  if (p == NULL || p->quantos < k) r = NULL;
  else {
    // q_esq: número de elementos menores
    int q_esq = 0;
    if (p->esq != NULL) q_esq = p->esq->quantos;

    // se for igual a k é esta a palavra
    if (q_esq == k) r = p->raiz;
    /* Se o número de menores for menor que k
    tenho de ir para a direita, mas na árvore
    da direita vão haver q_esq + 1 elementos
    menores inacessíveis
    */
    else if (q_esq < k) r = atRank (p->dir, k - q_esq - 1);
    else r = atRank (p->esq, k);
  }

  return r;
}

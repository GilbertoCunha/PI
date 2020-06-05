#include "teste.h"
#include <stdio.h>
#include <stdlib.h>

// Exercício 1
void ShowArray (int v[], int N) {
  for (int i=0; i<N; ++i) printf ("%d ", v[i]);
  printf ("\n");
}

void ShowLInt (LInt l) {
  while (l != NULL) {
    printf ("%d ", l->valor);
    l = l->prox;
  }
  printf ("\n");
}

void insere (LInt *l, int x) {
  while (*l != NULL) l = &((*l)->prox);

  *l = malloc (sizeof (struct slist));
  (*l)->valor = x;
  (*l)->prox = NULL;
}

LInt fromArray (int v[], int N) {
  LInt r = NULL;

  for (int i=0; i<N; ++i) insere (&r, v[i]);

  return r;
}

// Exercício 2
void ShowStack (Stack s) {
  if (s.lista != NULL) {
    for (int i=0; i<s.sp; ++i)
      printf ("%d ", s.lista->valores[i]);
    printf ("-> ");
    s.lista = s.lista->prox;
  }
  while (s.lista != NULL) {
    for (int i=0; i<BSize; ++i)
      printf ("%d ", s.lista->valores[i]);
    if (s.lista->prox != NULL) printf ("->");
    s.lista = s.lista->prox;
  }
  printf ("\n");
}

void initStack (Stack *s) {
  s->sp = 0;
  s->lista = NULL;
}

void push (Stack *s, int x) {
  if (s->sp == BSize) {
    LArrays novo = malloc (sizeof (struct larray));
    novo->valores[0] = x;
    novo->prox = s->lista;
    s->lista = novo;
    s->sp = 1;
  }
  else s->lista->valores[s->sp++] = x;
}

int pop (Stack *s, int *x) {
  int r = 0;

  if (s->lista == NULL) r = 1;
  else if (s->sp == 0) {
    LArrays tmp = s->lista;
    s->lista = s->lista->prox;
    free (tmp);
    s->sp = BSize-1;
    *x = s->lista->valores[s->sp];
  }
  else *x = s->lista->valores[--s->sp];

  return r;
}

// Exercício 3
void ShowLPares (LPares l) {
  while (l != NULL) {
    printf ("(%d,%d)", l->x, l->y);
    if (l->prox != NULL) printf ("-> ");
  }
  printf ("\n");
}

LPares zip (LInt a, LInt b, int *c) {
  LPares pt = NULL;
  LPares r = pt;
  *c = 0;

  while (a != NULL && b != NULL) {
    pt = malloc (sizeof (struct spares));
    pt->x = a->valor; a = a->prox;
    pt->y = b->valor; b = b->prox;
    pt->prox = NULL; pt = pt->prox;
    *c += 1;
  }

  return r;
}

// Exercício 3
void calculaPais (Tree t) {
  if (t != NULL) {
    if (t->esq != NULL) t->esq->pai = t;
    if (t->dir != NULL) t->dir->pai = t;
    calculaPais (t->esq);
    calculaPais (t->dir);
  }
}

Tree menor (Tree t) {
  while (t != NULL && t->esq != NULL) t = t->esq;

  return t;
}

Tree next (Tree t) {
  Tree r;
  if (t == NULL) r = NULL;
  else {
    // Encontrar menor elemento da direita
    Tree min_dir = menor (t->dir);

    // Se não existe, encontrar o primeiro
    // pai à esquerda
    if (min_dir != NULL) r = min_dir;
    else {
      while (t->pai != NULL && t->pai->esq != t) t = t->pai;
      if (t == NULL) r = NULL;
      else r = t;
    }
  }

  return r;
}

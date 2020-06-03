#include "exame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bitsUm (unsigned int n) {
  int r;

  if (n == 0) r = 0;
  else if (n == 1) r = 1;
  else r = n % 2 + bitsUm (n/2);

  return r;
}

int limpaEspacos (char t[]) {
  int i, j;

  for (i=0; t[i]!=0;) {
    if (t[i+1] == ' ' && t[i] == ' ')
      for (j=0; t[i+j]!=0; ++j) t[i+j] = t[i+j+1];
    else ++i;
  }

  return i;
}

int dumpL (LInt l, int v[], int N) {
  int r = 0;

  while (l != NULL && r<N) {
    v[r++] = l->valor;
    l = l->prox;
  }

  return r;
}

LInt parte (LInt l) {
  LInt r, *aux;
  aux = &r;

  while (l != NULL && l->prox != NULL) {
    *aux = l->prox;
    l->prox = l->prox->prox;
    aux = &((*aux)->prox);
    l = l->prox;
  }
  *aux = NULL;

  return r;
}

// Parte B
int fnotas_aux (Alunos a, int notas[21]) {
  int r;

  if (a == NULL) r = 0;
  else {
    r = fnotas (a->esq, notas);
    notas[a->nota]++;
    r += 1 + fnotas (a->dir, notas);
  }

  return r;
}

int fnotas (Alunos a, int notas[21]) {
  int r;

  for (int i=0; i<21; ++i) notas[i] = 0;
  r = fnotas_aux (a, notas);

  return r;
}

int rankAluno (Alunos a, int numero, int fnotas[21]) {
  int r;

  while (a != NULL && a->numero != numero)
    if (numero < a->numero) a = a->esq;
    else a = a->dir;

  if (a == NULL) r = -1;
  else {
    r = 0;
    for (int i=a->nota+1; i<21; ++i) r += fnotas[i];
  }

  return r;
}

void concat (StrList *l1, StrList l2) {
  while (*l1 != NULL) l1 = &((*l1)->prox);
  *l1 = l2;
}

int comNota (Alunos a, int nota, StrList *l) {
  int r;

  if (a == NULL) r = 0;
  else {
    r = comNota (a->esq, nota, l);
    if (a->nota == nota) {
      StrList novo = malloc (sizeof (struct strlist));
      novo->string = strdup (a->nome);
      novo->prox = NULL;
      concat (l, novo);
      ++r;
    }
    r += comNota (a->dir, nota, l);
  }

  return r;
}

void preenche (Alunos a, Alunos t[], int freq[21]) ; //???

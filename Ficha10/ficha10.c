#include "ficha10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAluno (Aluno a) {
  printf ("Aluno: %s | Número: %d | Nota: %d\n", a.nome, a.numero, a.nota);
}

void printTurma (Turma t) {
  if (t != NULL) {
    Aluno a = t->a;
    printTurma (t->esq);
    printAluno (a);
    printTurma (t->dir);
  }
}

int acrescentaAluno (Turma *t, Aluno a) {
  int r;
  if (*t == NULL) {
    *t = malloc (sizeof (struct arv));
    (*t)->a = a;
    (*t)->esq = (*t)->dir = NULL;
    r = 0;
  }
  else if ((*t)->a.numero == a.numero) r = 1;
  else if (a.numero < (*t)->a.numero) r = acrescentaAluno (&((*t)->esq), a);
  else r = acrescentaAluno (&((*t)->dir), a);

  return r;
}

Aluno *procura (Turma t, int numero) {
  Aluno *r;

  if (t == NULL) r = NULL;
  else if (t->a.numero == numero) r = &(t->a);
  else if (numero < t->a.numero) r = procura (t->esq, numero);
  else r = procura (t->dir, numero);

  return r;
}

int aprovados (Turma t, int numero) {
  int r = 0;

  if (t == NULL) r = 0;
  else {
    if (t->a.nota >= numero) ++r;
    r += aprovados (t->esq, numero);
    r += aprovados (t->dir, numero);
  }

  return r;
}

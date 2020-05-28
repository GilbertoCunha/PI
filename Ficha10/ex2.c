#include "ficha10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void acrescentaF (FILE *f, Aluno a) {
  long ant, pt, end_novo;
  FArv t, novo;

  ant = 0L;
  fseek (f, 0L, SEEK_SET);
  fread (&pt, sizeof (long), 1, f);

  while (pt != 0L) {
    fread (&t, sizeof (FArv), 1, f);
    ant = pt;
    if (a.numero < t.a.numero) pt = t.esq;
    else if (a.numero == t.a.numero) break;
    else pt = t.dir;
  }

  if (pt == 0L) {
    novo.a.nome = strdup (a.nome);
    novo.a.numero = a.numero;
    novo.a.nota = a.nota;
    novo.dir = novo.esq = 0L;

    fseek (f, 0L, SEEK_END);
    end_novo = ftell (f);
    fwrite (&novo, sizeof (FArv), 1, f);

    fseek (f, ant, SEEK_SET);
    if (ant == 0L) fwrite (&end_novo, sizeof (long), 1, f);
    else {
      fread (&t, sizeof (FArv), 1, f);
      if (a.numero < t.a.numero) t.esq = end_novo;
      else t.dir = end_novo;
      fseek (f, ant, SEEK_SET);
      fwrite (&t, sizeof (FArv), 1, f);
    }
  }
}

void writeArv (FILE *f, Turma t) {
  if (t != NULL) {
    acrescentaF (f, t->a);
    writeArv (f, t->esq);
    writeArv (f, t->dir);
  }
}

int lengthTurma (Turma t) {
  int r;

  if (t == NULL) r = 0;
  else r = 1 + lengthTurma (t->esq) + lengthTurma (t->dir);

  return r;
}

int turmaToArray (Turma t, Aluno v[]) {
  int r;

  if (t == NULL) r = 0;
  else {
    r = turmaToArray (t->esq, v);
    v[r++] = t->a;
    r += turmaToArray (t->dir, v+r);
  }

  return r;
}

Turma arrayToTurma (Aluno v[], int N) {
  Turma t;
  if (N == 0) t = NULL;
  else {
    int m = N/2;
    t = malloc (sizeof (struct arv));

    t->a.nome = strdup (v[m].nome);
    t->a.numero = v[m].numero;
    t->a.nota = v[m].nota;

    t->esq = arrayToTurma (v, m);
    t->dir = arrayToTurma (v+m+1, N-m-1);
  }

  return t;
}

void writeArvBalanced (FILE *f, Turma t) {
  int len = lengthTurma (t);
  Aluno *v = malloc (len * sizeof (Aluno));
  len = turmaToArray (t, v);
  t = arrayToTurma (v, len);
  writeArv (f, t);
}

Turma readArvAux (FILE *f, long add) {
  Turma r;

  if (add == 0L) r = NULL;
  else {
    FArv arv;
    r = malloc (sizeof (struct arv));

    fseek (f, add, SEEK_SET);
    fread (&arv, sizeof (FArv), 1, f);
    r->a.nome = strdup (arv.a.nome);
    r->a.numero = arv.a.numero;
    r->a.nota = arv.a.nota;

    r->esq = readArvAux (f, arv.esq);
    r->dir = readArvAux (f, arv.dir);
  }

  return r;
}

Turma readArv (FILE *f) {
  Turma r;
  long add;

  fseek (f, 0L, SEEK_SET);
  fread (&add, sizeof (long), 1, f);

  r = readArvAux (f, add);

  return r;
}

#ifndef _FICHA10
#define _FICHA10
#include <stdio.h>

typedef struct aluno {
  int numero;
  char *nome;
  int nota;
} Aluno;

typedef struct arv {
  Aluno a;
  struct arv *esq, *dir;
} *Turma;

// Exercício 1
int acrescentaAluno (Turma *t, Aluno a);
Aluno *procura (Turma t, int numero);
int aprovados (Turma t, int numero);
void printAluno (Aluno a);
void printTurma (Turma t);

typedef struct farv {
  Aluno a;
  long int esq, dir;
} FArv;

// Exercício 2
void writeArv (FILE *f, Turma t);
void writeArvBalanced (FILE *f, Turma t);
Turma readArv (FILE *f);
void acrescentaF (FILE *f, Aluno a);

// Exercício 3
void acrescentaAlunoF (FILE *f, Aluno a);
long procuraF (FILE *f, int numero);
int aprovadosF (FILE *f, int numero);
void printTurmaF (FILE *f);

#endif

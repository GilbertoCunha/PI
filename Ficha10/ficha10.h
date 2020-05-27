#ifndef _FICHA10
#define _FICHA10

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

#endif

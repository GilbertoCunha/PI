#include "ficha10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  // Criar os alunos
  Aluno G, M, R, S, C;
  G.nome = strdup ("Gilberto"); G.numero = 1; G.nota = 21;
  M.nome = strdup ("Marco"); M.numero = 2; M.nota = 420;
  R.nome = strdup ("Roberta"); R.numero = 3; R.nota = 422;
  S.nome = strdup ("Semanas"); S.numero = 4; S.nota = 20;
  C.nome = strdup ("Cascata"); C.numero = 5; C.nota = 69;

  // Adicionar alunos à turma
  Turma t = NULL;
  acrescentaAluno (&t, G);
  acrescentaAluno (&t, R);
  acrescentaAluno (&t, C);
  acrescentaAluno (&t, S);
  acrescentaAluno (&t, M);
  printf ("Turma: \n");
  printTurma (t);

  // Procurar alunos
  Aluno *g, *m, *r, *s, *c;
  g = procura (t, 1);
  m = procura (t, 2);
  r = procura (t, 3);
  s = procura (t, 4);
  c = procura (t, 5);

  // Imprimir alunos encontrados
  printf ("\nAlunos encontrados:\n");
  printAluno (*g);
  printAluno (*m);
  printAluno (*r);
  printAluno (*s);
  printAluno (*c);

  // Determinar numero de alunos aprovados
  int pass = aprovados (t, 420);
  printf ("\nAprovados:\n");
  printf ("Passaram %d alunos\n\n", pass);

  // Criar ficheiro
  FILE *f;
  f = fopen ("arvfile", "r+");
  if (f == NULL) {
    f = fopen ("arvfile", "w+");
    long x = 0L;
    fwrite (&x, sizeof (long), 1, f);
  }

  // Escrever no ficheiro
  writeArvBalanced (f, t);
  printf ("Turma escrita no ficheiro com sucesso\n\n");

  // Ler Turma do ficheiro e imprimi-la
  Turma t1 = readArv (f);
  printf ("Turma lida do ficheiro:\n");
  printTurma (t1);
  fclose (f);

  // Exercício 3
  FILE *f1 = fopen ("file_tree", "r+");
  if (f1 == NULL) {
    f1 = fopen ("file_tree", "w+");
    long x = 0L;
    fwrite (&x, sizeof (long), 1, f1);
  }
  writeArvBalanced (f1, t);
  long add_G = procuraF (f1, 1);
  printf ("\nO Gil está no endereço %ld do ficheiro\n", add_G);

  return 0;
}

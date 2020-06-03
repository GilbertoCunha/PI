#ifndef _EXAME
#define _EXAME

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

int bitsUm (unsigned int n);
int limpaEspacos (char t[]);
int dumpL (LInt l, int v[], int N);
LInt parte (LInt l);

typedef struct nodo {
  char nome [50];
  int numero;
  int nota;
  struct nodo *esq, *dir;
} *Alunos;

int fnotas (Alunos a, int notas[21]);
int rankAluno (Alunos a, int numero, int fnotas[21]);

typedef struct strlist {
  char *string;
  struct strlist *prox;
} *StrList;

int comNota (Alunos a, int nota, StrList *l);
void preenche (Alunos a, Alunos t[], int freq[21]);

#endif

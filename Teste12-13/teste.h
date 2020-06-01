#ifndef _TESTE
#define _TESTE

typedef struct lista {
  int valor;
  struct lista *prox;
} Nodo, *LInt;

int take (int n, LInt *l);

typedef struct abin {
  int valor;
  struct abin *esq, *dir;
} Nodo, *ABin;

int maiores (ABin a, int x);

// não saem ficheiros no teste

#define N 3
typedef struct bloco {
  int quantos;
  int valores[N];
  struct bloco *prox;
} Bloco, *LBloco;

int pertence (LBloco l, int x);
void acrescenta (LBloco *l, int n);

#endif

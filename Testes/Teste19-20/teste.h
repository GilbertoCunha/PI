#ifndef _TESTE
#define _TESTE

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

typedef struct dlist {
  int valor;
  struct dlist *ant, *prox;
} NodoD;

typedef struct {
  NodoD *front, *last;
} *DLint;

typedef struct nodoD {
  char *raiz;
  int quantos;
  struct nodoD *esq, *dir;
} *Palavras;

int verifica (int s[], int N);
void gera (LInt *l, int N);
LInt anterior (LInt l);
void pad (char *texto, int p, int N);

#endif

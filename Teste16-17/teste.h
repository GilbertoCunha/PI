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

// Parte a
int limpaEspacos (char t[]);
void transposta (int N, float m [N][N]);
LInt cloneL (LInt l);
int nivelV (ABin a, int n, int v[]);
void removeMaiorA (ABin *a);

#define MAXc 5
typedef struct chunk {
  int vs [MAXc];
  struct chunk *prox;
} *CList;

typedef struct stackC {
  CList valores;
  int sp;
} StackC;

// Parte b
int push (StackC *s, int x);
int pop (StackC *s, int *x);
int size (StackC s);
void reverse (StackC *s);
void reverse_rec (StackC *s);

#endif

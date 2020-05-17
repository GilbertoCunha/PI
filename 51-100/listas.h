#ifndef _LISTAS
#define _LISTAS

typedef struct slist {
  int valor;
  struct slist *prox;
} Nodo, *LInt;

int length (LInt l);
void freeL (LInt l);
void ImprimeL (LInt l);
LInt reverseL (LInt l);
void insertOrd (LInt *l, int x);
int removeOrd (LInt *l, int x);
void merge (LInt *r, LInt a, LInt b);
void splitQS (LInt l, int x, LInt *mx, LInt *Mx);
LInt parteAmeio (LInt *l);
int removeAll (LInt *l, int x);
int removeDups (LInt *l);
LInt parte (LInt l);

#endif

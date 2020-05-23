#ifndef _LISTAS
#define _LISTAS

typedef struct lista {
  int valor;
  struct lista *prox;
} Nodo, *LInt;

// Funções da ficha
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
int removeMaiorL (LInt *l);
void init (LInt *l);
void appendL (LInt *l, int x);
void concatL (LInt *a, LInt b);
LInt cloneL (LInt l);
LInt cloneRev (LInt l);
int maximo (LInt l);
int take (int n, LInt *l);
int drop (int n, LInt *l);
LInt Nforward (LInt l, int N);
int listToArray (LInt l, int v[], int N);
LInt arrayToList (int v[], int N);

#endif

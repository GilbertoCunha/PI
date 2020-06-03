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

// Parte A
void ShowLInt (LInt l);
int retiraNeg (int v[], int N);
int difConsecutivos (char s[]);
int maximo (LInt l);
int removeAll (LInt *l, int x);
LInt arrayToList (int v[], int N);

// Parte B
int minheapOK (ABin a);
int maxHeap (ABin a);
void removeMin (ABin *a);
void heapSort (int v[], int N);

#endif

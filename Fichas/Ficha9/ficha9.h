#ifndef _FICHA
#define _FICHA

// Exercício 1
typedef struct abin {
  char *pal;
  int ocorr;
  struct abin *esq, *dir;
} Entrada, *Dicionario;

void initDic (Dicionario *d);
int acrescenta (Dicionario *d, char *pal);
char *maisFreq (Dicionario d, int *c);

// Exercício 2
typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} Nodo, *ABin;

typedef struct lista {
  int valor;
  struct lista *prox;
} *LInt;

void ShowABin (ABin a);
void ShowLInt (LInt l);
LInt fromArray (int v[], int N);
ABin fromList (LInt l);
LInt inorderLaux (ABin a, LInt *end);
LInt inorderL (ABin a);

// Exercício 3
typedef struct dlista {
  int valor;
  struct dlista *prox, *ant;
} *DLInt;

void ShowDLInt (DLInt a);
DLInt DLfromArray (int v[], int N);
DLInt inorderDL (ABin a);

#endif

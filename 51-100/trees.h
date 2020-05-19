#ifndef _TREES
#define _TREES

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

typedef struct lista {
  int valor;
  struct lista *prox;
} *LInt;

// Funções auxiliares de teste
ABin insere (ABin a, int x);
ABin fromArray (int v[], int N);

// Funções da ficha
int altura (ABin a);
ABin cloneAB (ABin a);
void mirror (ABin *a);
void inorder (ABin a, LInt *l);
void preorder (ABin a, LInt *l);
void postorder (ABin a, LInt *l);
int depth (ABin a, int x);
int freeAB (ABin a);
int pruneAB (ABin *a, int l);
int iguaisAB (ABin a, ABin b);
LInt nivelL (ABin a, int n);
int nivelV (ABin a, int n, int v[]);
int dumpABin (ABin a, int v[], int N);
ABin somasAcA (ABin a);
int contaFolhas (ABin a);
ABin cloneMirror (ABin a);
int addOrd (ABin *a, int x);
int lookupAB (ABin a, int x);
int depthOrd (ABin a, int x);
int maiorAB (ABin a);
void removeMaiorA (ABin *a);
int quantosMaiores (ABin a, int x);
void listToBTree (LInt l, ABin *a);
int deProcura (ABin a);

#endif

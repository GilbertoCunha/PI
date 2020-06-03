#ifndef _EXAME
#define _EXAME

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

char *my_strcat (char s1[], char s2[]);
int remRep (char x[]);
int nivelV (ABin a, int n, int v[]);
int addOrd (ABin *a, int x);

typedef struct listaC {
  int coluna;
  float valor;
  struct listaC *prox;
} *Colunas;

typedef struct listaL {
  int linha;
  Colunas lcol;
  struct listaL *prox;
} *Mat;

void ShowMat (Mat m, int linhas, int colunas);
float getEntry (Mat m, int linha, int coluna);
void setEntry (Mat *m, int linha, int coluna, float valor);
Mat fromArray (int linhas, int colunas, int v[linhas][colunas]);
void addTo (Mat *m1, Mat m2);
void transpose (Mat *m);

#endif

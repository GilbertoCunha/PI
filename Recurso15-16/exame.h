#ifndef _EXAME
#define _EXAME

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

// Parte A
char *my_strcpy (char *dest, char source[]);
void strnoV (char s[]);
int dumpAbin (ABin a, int v[], int N);
int lookup (ABin a, int x);

typedef struct listP {
  char *pal;
  int cont;
  struct listaP *prox;
} Nodo, *Hist;

void ShowHist (Hist h);
int inc (Hist *h, char *pal);
char *remMaisFreq (Hist *h, int *count);

#endif

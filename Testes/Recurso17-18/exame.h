#ifndef _EXAME
#define _EXAME

typedef struct posicao {
  int x, y;
} Posicao;

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

// Parte A
char *my_strstr (char s1[], char s[]);
void truncW (char t[], int n);
int maisCentral (Posicao pos[], int N);
LInt somasAcL (LInt l);
int addOrd (ABin *a, int x);

typedef struct celula {
  char *palavra;
  int comp;
  struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e);
Palavras words (char *texto);
Palavras daLinha (Palavras t, int n);
void escreveLinha (Palavras p, int n);
void formata (char texto[], int largura);

#endif

#ifndef _EXAME
#define _EXAME

int palindrome (char s[]);
char *my_strlchr (char *s, char c);
void ordena (int nums[], int notas[], int n);

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

int dumpL (LInt l, int v[], int N);
LInt somas (LInt l);
void remreps (LInt l);

typedef struct sbin {
  int valor;
  struct sbin *esq, *dir;
} *ABin;

int contaFolhas (ABin a);

typedef struct posicao {
  int x, y;
  struct posicao *prox;
} Posicao, *Tabuleiro;

int validSol (int N, int board[N][N]);

#endif

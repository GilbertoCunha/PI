#ifndef _DIC
#define _DIC

typedef struct entrada {
  char *palavra;
  int ocorr;
  struct entrada *prox;
} *Palavras, Palavra;

typedef struct sDic {
  Palavras lista;
  int num_pal;
} Dicionario;

void showDic (Dicionario d);
void initDic (Dicionario *d);
int acrescenta (Dicionario *d, char *pal);
char *maisFreq (Dicionario d, int *c);

#endif

#ifndef _HASH
#define _HASH

#define SIZE 10

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

// Estrutura hash com listas ligadas
typedef struct shash {
  LInt valores[SIZE];
  int length;
  float load_factor;
} LHASH;

void ShowLHash (LHASH h);
int lhash (int value);
void init_lhash (LHASH *h);
int add_lhash (LHASH *h, int x);
LInt get_address_lhash (LHASH h, int x);
int rem_lhash (LHASH *h, int x);

#endif

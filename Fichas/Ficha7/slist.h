#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
  int valor;
  struct slist *prox;
} Nodo, *LInt;

LInt fromArray (int v[], int N) {
  int i; LInt r = NULL; LInt novo;

  for (i=N-1; i>=0; --i) {
    novo = malloc (sizeof (Nodo));
    novo->valor = v[i];
    novo->prox = r;
    r = novo;
  }

  return r;
}

void printList (LInt l) {
  if (l == NULL) printf ("\n");
  else if (l->prox == NULL) {
    printf ("%d", l->valor);
    printList (l->prox);
  }
  else {
    printf ("%d -> ", l->valor);
    printList (l->prox);
  }
}

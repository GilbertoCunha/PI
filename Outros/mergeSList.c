#include <stdio.h>
#include <stdlib.h>

typedef struct lligada *LInt;
typedef struct lligada {
  int valor;
  LInt prox;
} Nodo;

void cons (LInt *l, int x) {
  LInt novo = malloc (sizeof (Nodo));

  novo->valor = x;
  novo->prox = *l;
  *l = novo;
}

void snoc (LInt *l, int x) {
  LInt novo = malloc (sizeof (Nodo));
  novo->valor = x;
  novo->prox = NULL;

  while (*l != NULL) l = &((*l)->prox);

  *l = novo;
}

LInt fromArray (int a[], int N) {
  LInt r = NULL; int i;

  for (i=N-1; i>=0; --i) cons (&r, a[i]);

  return r;
}

LInt mergeL (LInt a, LInt b) {
  LInt r, last;

  if (a == NULL) return b;
  if (b == NULL) return a;

  if (a->valor < b->valor) {r = last = a; a = a->prox;}
  else {r = last = b; b = b->prox;}

  while (a!=NULL && b!=NULL)
    if (a->valor < b->valor) {last->prox = a; a = a->prox; last = last->prox;}
    else {last->prox = b; b = b->prox; last = last->prox;}

  if (a == NULL) last->prox = b;
  else last->prox = a;

  return r;
}

void printList (LInt l) {
  if (l == NULL) printf ("\n");
  else {
    printf ("%d ", l->valor);
    printList (l->prox);
  }
}

LInt mergeSort (LInt l) {
  // Fazer o  mergeSort de duas listas !
}

int main () {
  int a[10] = {12, 4, 17, -21, 15, 34, 1, 20, 19, 8};

  LInt l = fromArray (a, 10);
  printList (l);

  LInt l1 = fromArray (a, 5);
  printList (l1);

  LInt l2 = fromArray (a+5, 5);
  printList (l2);

  LInt l3 = mergeL (l1, l2);
  printList (l3);

  return 0;
}

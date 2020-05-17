#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

typedef struct slist {
  int valor;
  struct slist *prox;
} Nodo, *LInt;

ABin newABin (int r, ABin e, ABin d) {
  ABin a = malloc (sizeof (struct nodo));

  a->valor = r;
  a->esq = e;
  a->dir = d;

  return a;
}

ABin fromArray (int v[], int N) {
  ABin r = NULL, e, d;
  int m = N/2;

  if (N>0) {
    e = fromArray (v, m);
    d = fromArray (v+m+1, N-m-1);
    r = newABin (v[m], e, d);
  }

  return r;
}

int toArray (ABin a, int v[], int N) {
  int r = 0;

  if (a!=NULL && N>0) {
      r += toArray (a->esq, v+r, N-r);
      v[r++] = a->valor;
      r += toArray (a->dir, v+r, N-r);
  }

  return r;
}

int size (ABin a) {
  int r;

  if (a==NULL) r = 0;
  else r = 1 + size (a->esq) + size (a->dir);

  return r;
}

int main () {
  int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 95};

  ABin a1 = fromArray (a, 5);
}

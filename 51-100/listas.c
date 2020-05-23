#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

// 1: 10/10
int length (LInt l) {
  int r;

  for (r=0; l!=NULL; l=l->prox) ++r;

  return r;
}

// 2: 10/10
void freeL (LInt l) {
  LInt tmp;

  while (l!=NULL) {
    tmp = l;
    l = l->prox;
    free(tmp);
  }
}

// 3: 10/10
void ImprimeL (LInt l) {
  while (l!=NULL) {
    printf ("%d ", l->valor);
    l = l->prox;
  }
  printf("\n");
}

// 4: 10/10
LInt reverseL (LInt l) {
  LInt prox, ant = NULL;

  if (l!=NULL) {
    while (l->prox!=NULL) {
      prox = l->prox;
      l->prox = ant;
      ant = l;
      l = prox;
    }

    l->prox = ant;
  }

  return l;
}

// 5: 10/10
void insertOrd (LInt *l, int x) {
  LInt novo = malloc (sizeof (Nodo));
  novo->valor = x;

  while (*l!=NULL && (*l)->valor<x) l = &((*l)->prox);

  novo->prox = *l;
  *l = novo;
}

// 6: 10/10
int removeOrd (LInt *l, int x) {
  int r;

  while (*l!=NULL && (*l)->valor!=x) l = &((*l)->prox);

  if (*l==NULL) r=1;
  else {
    r = 0;
    *l = (*l)->prox;
  }

  return r;
}

// 7: 10/10
void merge (LInt *r, LInt a, LInt b) {
  while (a!=NULL && b!=NULL)
    if (a->valor < b->valor) {
      *r = a;
      r = &((*r)->prox);
      a = a->prox;
    }
    else {
      *r = b;
      r = &((*r)->prox);
      b = b->prox;
    }

  if (a==NULL) *r = b;
  else *r = a;
}

// 8: 10/10
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
  while (l!=NULL) {
    if (l->valor < x) {
      *mx = l;
      mx = &(l->prox);
    }
    else {
      *Mx = l;
      Mx = &(l->prox);
    }
    l = l->prox;
  }

  *mx = NULL;
  *Mx = NULL;
}

// 9: 10/10
// Parte a lista a meio (metade maior é mantida)
LInt parteAmeio (LInt *l) {
  LInt ant, r = *l;
  int i, size = length(*l);

  for (i=0; i<size/2; ++i) {
    ant = *l;
    *l = (*l)->prox;
  }

  if (i==0) r = NULL;
  else ant->prox = NULL;

  return r;
}

// 10: 10/10
int removeAll (LInt *l, int x) {
  int r = 0;

  while (*l!=NULL)
    if ((*l)->valor == x) {
      *l = (*l)->prox;
      ++r;
    }
    else l = &((*l)->prox);

  return r;
}

int isIn (int x, int v[], int N) {
  int i, r;

  for (i=0; i<N && v[i]!=x; ++i);

  if (i==N) r = 0;
  else r = 1;

  return r;
}

// 11: 10/10
int removeDups (LInt *l) {
  int r = 0, size = length (*l);
  int elems[size];

  LInt tmp;
  while (*l!=NULL && (*l)->prox!=NULL)
    if (isIn ((*l)->valor, elems, size)) {
      tmp = *l;
      *l = (*l)->prox;
      free (tmp);
    }
    else {
      elems[r++] = (*l)->valor;
      l = &((*l)->prox);
    }

  return r;
}

// 12: 10/10
int removeMaiorL (LInt *l) {
  LInt *l_aux = l;
  int r = (*l)->valor;
  l = &((*l)->prox);

  // Encontrar o maior elemento
  while (*l != NULL) {
    if ((*l)->valor > r) r = (*l)->valor;
    l = &((*l)->prox);
  }

  // Remover o maior elemento
  while ((*l_aux)->valor != r)
    l_aux = &((*l_aux)->prox);

  LInt tmp = *l_aux;
  *l_aux = (*l_aux)->prox;
  free (tmp);

  return r;
}

// 13: 10/10
void init (LInt *l) {
  while ((*l)->prox != NULL)
  l = &((*l)->prox);

  LInt tmp = *l;
  *l = (*l)->prox;
  free (tmp);
}

// 14: 10/10
void appendL (LInt *l, int x) {
  while (*l != NULL) l = &((*l)->prox);

  LInt novo = malloc (sizeof (struct lista));
  novo->valor = x;
  novo->prox = NULL;

  *l = novo;
}

// 15: 10/10
void concatL (LInt *a, LInt b) {
  while (*a != NULL) a = &((*a)->prox);
  *a = b;
}

// 16: 10/10
LInt cloneL (LInt l) {
  LInt r;

  if (l == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct lista));
    r->valor = l->valor;
    r->prox = cloneL (l->prox);
  }

  return r;
}

// 17: 10/10
LInt cloneRev (LInt l) {
  LInt r = NULL;
  LInt novo;

  while (l != NULL) {
    novo = malloc (sizeof (struct lista));
    novo->valor = l->valor;
    novo->prox = r;
    r = novo;
    l = l->prox;
  }

  return r;
}

// 18: 10/10
int maximo (LInt l) {
  int r = l->valor;
  l = l->prox;

  while (l != NULL) {
    if (l->valor > r) r = l->valor;
    l = l->prox;
  }

  return r;
}

// 19: 10/10
int take (int n, LInt *l) {
  int r = 0;

  while (*l != NULL && n != 0) {
    l = &((*l)->prox);
    ++r; --n;
  }

  while (*l != NULL) {
    LInt tmp = *l;
    *l = (*l)->prox;
    free (tmp);
  }

  return r;
}

// 20: 10/10
int drop (int n, LInt *l) {
  int r = 0;
  LInt tmp;

  while (*l != NULL && n != 0) {
    tmp = *l;
    *l = (*l)->prox;
    free (tmp);
    ++r; --n;
  }

  return r;
}

// 21: 10/10
LInt Nforward (LInt l, int N) {
  for (int i=0; i<N; ++i) l = l->prox;

  return l;
}

// 22: 10/10
int listToArray (LInt l, int v[], int N) {
  int r;

  for (r = 0; l!=NULL && r<N; ++r) {
    v[r] = l->valor;
    l = l->prox;
  }

  return r;
}

// 23: 10/10
LInt arrayToList (int v[], int N) {
  LInt r = NULL;
  LInt *sitio = &r;

  for (int i=0; i<N; ++i) {
    *sitio = malloc (sizeof (struct lista));
    (*sitio)->valor = v[i];
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
  }

  return r;
}

// 24: 10/10
LInt somasAcL (LInt l) {
  LInt r = NULL;
  LInt *sitio = &r;

  int counter = 0;
  while (l != NULL) {
    counter += l->valor;
    *sitio = malloc (sizeof (struct lista));
    (*sitio)->valor = counter;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

// 25: 10/10
void remreps (LInt l) {
  while (l != NULL && l->prox != NULL) {
    if (l->valor == l->prox->valor) l->prox = l->prox->prox;
    else l = l->prox;
  }
}

// 26: 10/10
LInt rotateL (LInt l) {
  LInt head = l;

  while (l != NULL && l->prox != NULL) l = l->prox;

  if (l != NULL) {
    l->prox = head;
    l = head->prox;
    head->prox = NULL;
  }

  return l;
}

// 27: 10/10
LInt parte (LInt l) {
  LInt r, *aux;
  aux = &r;

  while (l!=NULL && l->prox!=NULL) {
      *aux = l->prox;
      l->prox=l->prox->prox;
      aux = &((*aux)->prox);
      l = l->prox;
  }
  *aux = NULL;

  return r;
}

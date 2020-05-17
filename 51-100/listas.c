#include <stdio.h>
#include <stdlib.h>

// 1: 10/10
// Calcula o tamanho da lista l
int length (LInt l) {
  int r;

  for (r=0; l!=NULL; l=l->prox) ++r;

  return r;
}

// 2: 10/10
// Liberta o espaço da lista l
void freeL (LInt l) {
  LInt tmp;

  while (l!=NULL) {
    tmp = l;
    l = l->prox;
    free(tmp);
  }
}

// 3: 10/10
// Imprime os elementos da lista l
void ImprimeL (LInt l) {
  while (l!=NULL) {
    printf ("%d ", l->valor);
    l = l->valor;
  }
  printf("\n");
}

// 4: 10/10
// Inverte a lista l
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
// Insere ordenadamente numa lista ordenada
void insertOrd (LInt *l, int x) {
  LInt novo = malloc (sizeof (Nodo));
  novo->valor = x;

  while (*l!=NULL && (*l)->valor<x) l = &((*l)->prox);

  novo->prox = *l;
  *l = novo;
}

// 6: 10/10
// Remove um elemento de uma lista ordenada
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
// Junta duas listas ordenadas
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
// Coloca em *mx menores que x e em Mx o resto
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
  int size = length(*l);

  for (i=0; i<size/2; ++i) {
    ant = *l;
    *l = (*l)->prox;
  }

  if (i==0) r = NULL;
  else ant->prox = NULL;

  return r;
}

// 10: 10/10
// Remove todas as ocorrências de um elemento na lista
// Retorna o nº de elementos removidos
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

// 11: 10/10
// Remove os valores duplicados
int isIn (int x, int v[], int N) {
  int i, r;

  for (i=0; i<N && v[i]!=x; ++i);

  if (i==N) r = 0;
  else r = 1;

  return r;
}

int removeDups (LInt *l) {
  int r = 0, size = length (*l);
  int elems[size];

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

// 27:
// Mantém posições ímpares em l, posições pares vão para lista resultante
LInt parte (LInt l) {
  LInt r, *aux, tmp;
  aux = &r;
  tmp = l;

  while (l!=NULL && l->prox!=NULL) {
      *aux = l->prox;
      l->prox=l->prox->prox;
      aux = &((*aux)->prox);
      l = l->prox;
  }
  *aux = NULL;

  return r;
}

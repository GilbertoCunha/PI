#include "exame.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strcat (char s1[], char s2[]) {
  int i, j;

  for (i=0; s1[i]!=0; ++i);
  for (j=0; s2[j]!=0; ++j) s1[i+j] = s2[j];
  s1[i+j] = 0;

  return s1;
}

int remRep (char x[]) {
  int r = 0;

  while (x[r] != 0) {
    if (x[r+1] == x[r])
      for (int i=r; x[i]!=0; ++i) x[i] = x[i+1];
    else ++r;
  }

  return r;
}

int nivelV (ABin a, int n, int v[]) {
  int r;

  if (a == NULL) r = 0;
  else if (n == 1) {
    v[0] = a->valor;
    r = 1;
  }
  else {
    r = nivelV (a->esq, n-1, v);
    r+= nivelV (a->dir, n-1, v+r);
  }

  return r;
}

int addOrd (ABin *a, int x) {
  int r;

  while (*a != NULL && (*a)->valor != x)
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);

  if (*a == NULL) {
    r = 0;
    *a = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
  }
  else r = 1;

  return r;
}

// Parte B
void ShowColuna (Colunas c, int colunas) {
  int j;

  for (j=0; j<colunas; ++j) {
    if (c != NULL && j == c->coluna) {
      printf ("%.2f ", c->valor);
      c = c->prox;
    }
    else printf ("0 ");
  }
}

void ShowMat (Mat m, int linhas, int colunas) {
  int i, j;
  for (i=0; i<linhas; i++) {
    if (m != NULL && i == m->linha) {
      ShowColuna (m->lcol, colunas);
      m = m->prox;
    }
    else for (j=0; j<colunas; ++j) printf ("0 ");
    printf ("\n");
  }
}

float getEntry (Mat m, int linha, int coluna) {
  int r;

  while (m != NULL && m->linha != linha) m = m->prox;

  if (m == NULL) r = 0;
  else {
    while (m->lcol != NULL && m->lcol->coluna != coluna)
      m->lcol = m->lcol->prox;
    if (m->lcol == NULL) r = 0;
    else r = m->lcol->valor;
  }

  return r;
}

void new_Mat (Mat *r, float valor, int linha, int coluna) {
  *r = malloc (sizeof (struct listaL));
  (*r)->lcol = malloc (sizeof (struct listaC));
  (*r)->lcol->valor = valor;
  (*r)->linha = linha; (*r)->lcol->coluna = coluna;
  (*r)->prox = NULL; (*r)->lcol->prox = NULL;
}

void setColumn (Colunas *c, int coluna, int valor) {
  while (*c != NULL && (*c)->coluna < coluna) c = &((*c)->prox);

  if (*c == NULL) {
    *c = malloc (sizeof (struct listaC));
    (*c)->coluna = coluna;
    (*c)->valor = valor;
    (*c)->prox = NULL;
  }
  else if ((*c)->coluna != coluna) {
    Colunas novo = malloc (sizeof (struct listaC));
    novo->valor = valor;
    novo->coluna = coluna;
    novo->prox = *c;
    *c = novo;
  }
  else (*c)->valor = valor;
}

void setEntry (Mat *m, int linha, int coluna, float valor) {
  while (*m != NULL && linha > (*m)->linha) m = &((*m)->prox);

  if (*m == NULL) {
    // Adicionar nova linha no fim
    new_Mat (m, valor, linha, coluna);
  }
  else if ((*m)->linha != linha) {
    // Adicionar nova linha no meio
    Mat novo; new_Mat (&novo, valor, linha, coluna);
    novo->prox = *m;
    *m = novo;
  }
  else setColumn (&((*m)->lcol), coluna, valor);
}

Mat fromArray (int linhas, int colunas, int v[linhas][colunas]) {
  Mat r = NULL;

  for (int i=0; i<linhas; ++i) {
    for (int j=0; j<colunas; ++j)
      if (v[i][j] != 0) setEntry (&r, i, j, v[i][j]);
  }

  return r;
}

void addColuna (Colunas *c1, Colunas c2) {
  while (*c1 != NULL && c2 != NULL) {
    if ((*c1)->coluna == c2->coluna) {
      (*c1)->valor += c2->valor;
      c1 = &((*c1)->prox);
      c2 = c2->prox;
    }
    else if ((*c1)->coluna < c2->coluna)
      c1 = &((*c1)->prox);
    else {
      Colunas nova = malloc (sizeof (struct listaC));
      nova->valor = c2->valor;
      nova->coluna = c2->coluna;
      nova->prox = *c1;
      *c1 = nova;
      c2 = c2->prox;
    }
  }

  if (*c1 == NULL) *c1 = c2;
}

void addTo (Mat *m1, Mat m2) {
  while (*m1 != NULL && m2 != NULL) {
    if ((*m1)->linha < m2->linha) m1 = &((*m1)->prox);
    else if ((*m1)->linha == m2->linha) {
      addColuna (&((*m1)->lcol), m2->lcol);
      m1 = &((*m1)->prox);
      m2 = m2->prox;
    }
    else {
      Mat nova = malloc (sizeof (struct listaL));
      nova->linha = m2->linha;
      nova->lcol = m2->lcol;
      nova->prox = *m1;
      *m1 = nova;
      m1 = &((*m1)->prox);
      m2 = m2->prox;
    }
  }

  if (*m1 == NULL) *m1 = m2;
}

void transpose (Mat *m); // ???

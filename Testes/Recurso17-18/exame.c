#include "exame.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Parte A
char *my_strstr (char s1[], char s2[]) {
  char *r;
  int i, j=0;

  for (i=0; s1[i]!=0 && s2[j]!=0; ++i) {
    for (j=0; s2[j]!=0 && s1[i+j]!=0 && s2[j]==s1[i+j]; ++j);
    if (s2[j] == 0) r = &s1[i];
  }

  return r;
}

void truncW (char t[], int n) {
  int i = 0, j, k;
  while (t[i] != 0) {
    while (t[i] == ' ') ++i;

    for (j=0; t[i+j]!=0 && t[i+j]!=' '; ++j);

    if (j > n) {
      for (k=i+n; t[k+j-n]!=0 && t[k+j-n]!=' '; ++k)
        t[k] = t[k+j-n];
      t[k] = 0;
    }
    else i += j;
  }
}

int maisCentral (Posicao pos[], int N) {
  int r, max, dist;

  if (N == 0) r = -1;
  else {
    r = 0; max = pos[0].x^2 + pos[0].y^2;

    for (int i=1; i<N; ++i) {
      dist = pos[i].x^2 + pos[i].y^2;
      if (dist > max) {
        max = dist;
        r = i;
      }
    }
  }

  return r;
}

LInt somasAcL (LInt l) {
  LInt r = NULL;
  LInt *sitio = &r;
  int conta = 0;

  while (l != NULL) {
    conta += l->valor;
    *sitio = malloc (sizeof (struct slist));
    (*sitio)->valor = conta;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

int addOrd (ABin *a, int x) {
  int r;

  while (*a != NULL && (*a)->valor != x)
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);

  if ((*a)->valor == x) r = 1;
  else {
    r = 0;
    (*a) = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
  }

  return r;
}

// Parte B
int daPalavra (char *s, int *e) {
  int r=0, i=0;
  *e = 0;

  while (isspace (s[i])) ++i;
  *e = i;

  while (!isspace (s[i+r]) && s[i+r]!=0) ++r;

  return r;
}

Palavras words (char *texto) {
  Palavras r = NULL;
  Palavras *sitio = &r;

  int spaces, size;
  while (*texto != 0) {
    size = daPalavra (texto, &spaces);

    *sitio = malloc (sizeof (struct celula));
    (*sitio)->palavra = malloc (size * sizeof (char));
    for (int i=0; i<size; ++i) (*sitio)->palavra[i] = *(texto+spaces+i);
    (*sitio)->comp = size;
    (*sitio)->prox = NULL;

    sitio = &((*sitio)->prox);
    texto = texto + spaces + size;
  }

  return r;
}

Palavras daLinha (Palavras t, int n) {
  Palavras ant = NULL, r = t;
  int caracteres=0, palavras=0;

  while (r != NULL && caracteres + r->comp < n) {
    caracteres += 1 + r->comp;
    ant = r; r = r->prox;
  }
  // Pelo menos uma palavra
  if (ant == NULL) {
    ant = r;
    r = r->prox;
  }
  ant->prox = NULL;

  return r;
}

void escreveLinha (Palavras p, int n) {
  int caracteres = 0;
  int palavras = 0;
  Palavras pt = p;

  while (pt != NULL) {
    palavras += 1;
    caracteres += pt->comp;
    pt = pt->prox;
  }

  int i, spaces = n - caracteres;
  while (p != NULL) {
    printf ("%s", p->palavra);
    for (i=0; i<spaces/palavras; ++i) printf (" ");

    palavras--;
    spaces -= i;
    p = p->prox;
  }
  printf ("\n");
}

void liberta (Palavras p) {
  Palavras tmp;

  while (p != NULL) {
    tmp = p;
    p = p->prox;
    free (tmp);
  }
}

void formata (char texto[], int largura) {
  Palavras lista = words (texto);
  Palavras aux;

  while (lista != NULL) {
    aux = daLinha (lista, largura);
    escreveLinha (lista, largura);
    liberta (lista);
    lista = aux;
  }
}

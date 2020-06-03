#include "exame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy (char *dest, char source[]) {
  int i;
  for (i=0; source[i]!=0; ++i) dest[i] = source[i];
  dest[i] = 0;

  return dest;
}

int isVowel (char c) {
  char vowels[11] = "aeiouAEIOU";
  int r, i;

  for (i=0; vowels[i]!=0 && c!=vowels[i]; ++i);

  if (i==10) r = 0; // Não pertence
  else r = 1; // Pertence

  return r;
}

void leftShift (char s[]) {
  for (int i=0; s[i]!=0; ++i) s[i] = s[i+1];
}

void strnoV (char s[]) {
  int i = 0;

  while (s[i]!=0) {
    if (isVowel (s[i])==1) leftShift (s+i);
    else ++i;
  }
}

int dumpAbin (ABin a, int v[], int N) {
  int r;

  if (a == NULL || N==0) r = 0;
  else {
    r = dumpAbin (a->esq, v, N);
    if (r<N) v[r++] = a->valor;
    if (r<N) r += dumpAbin (a->dir, v+r, N-r);
  }

  return r;
}

int lookupAB (ABin a, int x) {
  int r;

  while (a != NULL && a->valor != x)
    if (x < a->valor) a = a->esq;
    else a = a->dir;

  if (a == NULL) r = 0;
  else r = 1;

  return r;
}

// Parte B
void ShowHist (Hist h) {
  while (h != NULL) {
    printf ("%s: %d ", h->pal, h->cont);
    if (h->prox != NULL) printf ("-> ");
    h = h->prox;
  }
  printf ("\n");
}

int inc (Hist *h, char *pal) {
  while (*h != NULL && strcmp((*h)->pal, pal) < 0)
    h = &((*h)->prox);

  if (*h == NULL || strcmp ((*h)->pal, pal)!=0) {
    Hist novo = malloc (sizeof (Nodo));
    novo->pal = strdup (pal);
    novo->cont = 1;
    novo->prox = *h;
    *h = novo;
  }
  else (*h)->cont++;

  return (*h)->cont;
}

char *remMaisFreq (Hist *h, int *count) {
  char *r;
  Hist *pt = h;

  if (*h != NULL) *count = (*h)->cont;
  while (*h != NULL) {
    if ((*h)->cont > *count) {
      *count = (*h)->cont;
      pt = h;
    }
    h = &((*h)->prox);
  }

  r = strdup ((*pt)->pal);
  *pt = (*pt)->prox;

  return r;
}

#include "dicionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showDic (Dicionario d) {
  Palavras lista = d.lista;
  printf ("Dicionário com %d palavras\n", d.num_pal);

  while (lista!=NULL) {
    printf ("%s :: %d\n", lista->palavra, lista->ocorr);
    lista = lista->prox;
  }
}

void initDic (Dicionario *d) {
  d->lista = NULL;
  d->num_pal = 0;
}

int acrescenta (Dicionario *d, char *pal) {
  Palavras *sitio = &(d->lista);

  while (*sitio!=NULL && strcmp((*sitio)->palavra, pal)<0)
    sitio = &((*sitio)->prox);

  Palavras nova = malloc (sizeof (Palavra));
  nova->palavra = strdup (pal);
  nova->ocorr = 1;

  if (*sitio==NULL) {
    nova->prox = NULL;
    *sitio = nova;
  }
  else if (strcmp ((*sitio)->palavra, pal)==0)
    (*sitio)->ocorr++;
  else {
    d->num_pal++;
    nova->prox = *sitio;
    *sitio = nova;
  }

  return (*sitio)->ocorr;
}

char *maisFreq (Dicionario d, int *c) {
  char *r;
  Palavras lista = d.lista;
  int max_ocorr = 0;

  while (lista!=NULL) {
    if (lista->ocorr > max_ocorr) {
      r = strdup (lista->palavra);
      max_ocorr = lista->ocorr;
    }
    lista = lista->prox;
  }

  *c = max_ocorr;

  return r;
}

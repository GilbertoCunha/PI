#include "ficha9.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initDic (Dicionario *d) {
  d = NULL;
}

int acrescenta (Dicionario *d, char *pal) {
  while (*d!=NULL && strcmp (pal, (*d)->pal)!=0)
    if (strcmp (pal, (*d)->pal) < 0) d = &((*d)->esq);
    else d = &((*d)->dir);

  if (*d == NULL) {
    *d = malloc (sizeof (Entrada));
    (*d)->pal = strdup (pal);
    (*d)->ocorr = 1;
    (*d)->esq = (*d)->dir = NULL;
  }
  else (*d)->ocorr++;

  return (*d)->ocorr;
}

char *maisFreq (Dicionario d, int *c) {
  char *r;

  if (d == NULL) {
    r = strdup ("\0");
    *c = 0;
  }
  else if (d->dir==NULL && d->esq==NULL) {
    r = strdup (d->pal);
    *c = d->ocorr;
  }
  else {
    int num_esq, num_dir;
    char *mf_esq = strdup ( maisFreq(d->esq, &num_esq));
    char *mf_dir = strdup ( maisFreq(d->dir, &num_dir));
    if (num_esq > num_dir && num_esq > d->ocorr) {
      r = strdup (mf_esq);
      *c = num_esq;
    }
    else if (num_dir > num_esq && num_dir > d->ocorr) {
      r = strdup (mf_dir);
      *c = num_dir;
    }
    else {
      r = strdup (d->pal);
      *c = d->ocorr;
    }
  }

  return r;
}

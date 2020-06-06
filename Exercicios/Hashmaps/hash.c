#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

void ShowLHash (LHASH h) {
  printf ("HashTable: \n");
  for (int i=0; i<SIZE; ++i) {
    while (h.valores[i] != NULL) {
      printf ("%d -> ", h.valores[i]->valor);
      h.valores[i] = h.valores[i]->prox;
    }
    printf ("NULL\n");
  }
  printf ("LOAD_FACTOR = %f\n", h.load_factor);
}

int lhash (int value) {
  // Calcula o índice para um certo valor
  int r;

  r = value % SIZE;
  if (r < 0) r = -r;

  return r;
}

void init_lhash (LHASH *h) {
  // Inicializa uma hash table de listas ligadas
  for (int i=0; i<SIZE; ++i) h->valores[i] = NULL;
  h->length = 0;
  h->load_factor = 0;
}

int add_lhash (LHASH *h, int x) {
  // Adiciona o elemento x à hashtable
  int r = 0;

  LInt novo = malloc (sizeof (struct slist));

  if (novo == NULL) r = 1;
  else {
    int index = lhash (x);
    if (h->valores[index] == NULL) {
      h->length++;
      h->load_factor = (float)h->length / (float)SIZE;
    }
    novo->valor = x;
    novo->prox = h->valores[index];
    h->valores[index] = novo;
  }

  return r;
}

LInt get_address_lhash (LHASH h, int x) {
  /* Devolve o endereço da lista ligada
  onde se encontra o elemento x */
  LInt r, aux;
  int index = lhash (x);
  aux = h.valores[index];

  while (aux != NULL &&  aux->valor != x)
    aux = aux->prox;

  if (aux != NULL && aux->valor != x) r = NULL;
  else r = aux;

  return r;
}

int rem_lhash (LHASH *h, int x) {
  // Remove o elemento x da hashtable
  int r, index = lhash (x);
  LInt *aux = &(h->valores[index]);

  while (*aux != NULL && (*aux)->valor != x) aux = &((*aux)->prox);

  if (aux == NULL) r = 1;
  else {
    r = 0;
    *aux = (*aux)->prox;
    if (h->valores[index] == NULL) {
      h->length--;
      h->load_factor = (float) h->length / (float) SIZE;
    }
  }

  return r;
}

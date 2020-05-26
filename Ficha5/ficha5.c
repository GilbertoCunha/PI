#include "ficha5.h"
#include <stdio.h>
#include <stdlib.h>

void ShowArray (int v[], int N) {
  for (int i=0; i<N; ++i)
    printf ("%d ", v[i]);

  printf ("\n");
}

void insere (int v[], int N, int x) {
  int i;
  for (i=0; i<N && v[i]<x; ++i);
  for (int j = N; j>i; --j) v[j] = v[j-1];
  v[i] = x;
}

void iSort (int v[], int N) {
  for (int i=0; i<N; ++i)
    insere (v, i, v[i]);
}

int maxInd (int v[], int N) {
  int r;
  if (N == 0) r = -1;
  else {
    r = 0;
    int max = v[0];
    for (int i=0; i<N; ++i)
      if (v[i]>max) {
        r = i;
        max = v[i];
      }
  }

  return r;
}

void maxSort (int v[], int N) {
  int i, j, tmp;

  for (i=0; i<N; ++i) {
    j = maxInd (v, N-i);
    tmp = v[N-1-i];
    v[N-1-i] = v[j];
    v[j] = tmp;
  }
}

void swap (int v[], int a, int b) {
  int tmp = v[a];
  v[a] = v[b];
  v[b] = tmp;
}

void bubble (int v[], int N) {
  for (int i=1; i<N; ++i)
    if (v[i-1]>v[i])
      swap (v, i-1, i);
}

void bubbleSort (int v[], int N) {
  for (int i=0; i<N; ++i)
    bubble (v, N);
}

int isOrdered (int v[], int N) {
  int i, r;

  for (i=1; i<N && v[i]>v[i-1]; ++i);

  if (i == N) r = 1;
  else r = 0;

  return r;
}

void fastbubbleSort (int v[], int N) {
  while (!isOrdered (v, N)) bubble (v, N);
}

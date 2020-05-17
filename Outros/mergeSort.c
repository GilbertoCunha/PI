#include <stdio.h>
#include <stdlib.h>

void mergeV (int a[], int na, int b[], int nb) {
  int r[na+nb];
  int ia, ib, ir;
  ia = ib = ir = 0;

  while (ia < na && ib < nb)
    if (a[ia] < b[ib])
      r[ir++] = a[ia++];
    else r[ir++] = b[ib++];

  if (ia == na)
    while (ib < nb) r[ir++] = b[ib++];
  else
    while (ia < na) r[ir++] = a[ia++];

  for (ia = 0; ia < ir; ++ia) a[ia] = r[ia];
}

void mergeSort (int a[], int N) {
  int m;
  if (N > 1) {
    m = N/2;
    mergeSort (a, m);
    mergeSort (a+m, N-m);
    mergeV (a, m, a+m, N-m);
  }
}

void printArray (int a[], int N) {
  if (N == 0) printf ("\n");
  else {
    printf("%d ", a[0]);
    printArray (a+1, N-1);
  }
}

int main () {
  int a[10] = {12, 4, 17, -21, 15, 34, 1, 20, 19, 8};
  int i;

  printArray (a, 10);
  mergeSort (a, 10);
  printArray (a, 10);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#include "dlist.h"

int main () {
  int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // LInt from array
  printf ("LInt from array: ");
  LInt l1 = fromArray (v1, 5);
  printList (l1);

  // DLInt from array
  printf ("DLInt from array: ");
  DLInt d1 = DfromArray (v1, 5);
  printDList (d1);

  // Go to end
  printf ("Go to end of DLInt: ");
  fim (&d1);
  printDList (d1);

  // Go to start
  printf ("Go to start of DLInt: ");
  inicio (&d1);
  printDList (d1);

  // DLInt from array
  printf ("DLInt from array 2: ");
  DLInt d2 = DfromArray (v1+5, 5);
  printDList (d2);

  // Concatenate DLInt
  printf ("Concatenate DLInts: ");
  concat (&d1, d2);
  printDList (d1);

  // To LInt
  printf ("To LInt: ");
  LInt l2 = toLInt (d2);
  printList (l2);

  // From LInt
  printf ("From first LInt: ");
  DLInt d3 = fromLInt (l1);
  printDList (d3);

  return 0;
}

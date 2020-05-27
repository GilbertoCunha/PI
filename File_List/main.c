#include "file_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *f;
	Lista l1;

	long x;

	l1 = NULL;
	l1 = acrescentaL (l1, "Maria");
	l1 = acrescentaL (l1, "Ana");
	l1 = acrescentaL (l1, "Rita");

  printf ("Lista: ");
	ShowLista (l1);

	f = fopen ("Lista", "r+");
	if (f == NULL) {
		f = fopen ("Lista", "w+");
		x = 0L;
		fwrite (&x, sizeof(long), 1, f);
	}

	acrescentaF (f, "Maria");
	acrescentaF (f, "Ana");
	acrescentaF (f, "Rita");

  printf ("FileList: ");
  ShowFileList (f);

	fclose (f);


	return 0;
}

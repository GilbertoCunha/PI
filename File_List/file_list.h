#ifndef _FILELIST
#define _FILELIST
#include <stdio.h>

typedef struct slist {
	char nome [100];
	struct slist *prox;
} *Lista;

Lista acrescentaL (Lista l, char *n);
void ShowLista (Lista l);

typedef struct flist {
	char nome [100];
	long int prox;
} Nodo;

void acrescentaF (FILE *f, char *n);
void ShowFileList (FILE *f);

#endif

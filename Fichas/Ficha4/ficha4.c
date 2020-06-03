#include "ficha4.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int minusculas (char s[]) {
  int r = 0;

  for (int i=0; s[i]!=0; ++i)
    if (s[i]>='a' && s[i]<='z') ++r;

  return r;
}

int contalinhas (char s[]) {
  int r;

  if (s[0] == 0) r = 0;
  else {
    r = 1;

    for (int i=0; s[i]!=0; ++i)
      if (s[i]=='\n') ++r;
  }

  return r;
}

int contaPal (char s[]) {
  int len, r = 0;
  char last = ' ';

  len = strlen (s);

  if (len > 0) last = s[0];

  for (int i=0; s[i]!=0; ++i) {
    if (isspace(s[i]) && !isspace(last))
      ++r;
    last = s[i];
  }

  if (!isspace(last)) ++r;

  return r;
}

int procura (char *p, char *ps[], int N) {
  int r = -1;

  for (int i=0; i<N; ++i)
    if (strcmp (p, ps[i]) == 0) r = i;

  return r;
}

void ShowStack (STACK s) {
  int i;

  printf ("STACK: ");

  for (i = s.sp - 1; i>0; --i)
    printf ("%d <- ", s.valores[i]);

  printf ("%d\n", s.valores[0]);
}

void initStack (STACK *s) {
  s->sp = 0;
}

int isEmpty (STACK *s) {
  int r;

  if (s->sp == 0) r = 0;
  else r = 1;

  return r;
}

int push (STACK *s, int x) {
  int r = 0;

  if (s->sp < MAX) s->valores[(s->sp)++] = x;
  else r = 1;

  return r;
}

int pop (STACK *s, int *x) {
  int r = 0;

  if (s->sp > 0) *x = s->valores[--(s->sp)];
  else r = 1;

  return r;
}

int top (STACK *s, int *x) {
  int r = 0;

  if (s->sp > 0) *x = s->valores[s->sp - 1];
  else r = 1;

  return r;
}

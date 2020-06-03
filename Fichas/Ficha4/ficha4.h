#ifndef _FICHA4
#define _FICHA4

int minusculas (char s[]);
int contalinhas (char s[]);
int contaPal (char s[]);
int procura (char *p, char *ps[], int N);

#define MAX 100
typedef struct stack {
  int sp;
  int valores [MAX];
} STACK;

void ShowStack (STACK s);
void initStack (STACK *s);
int isEmpty (STACK *s);
int push (STACK *s, int x);
int pop (STACK *s, int *x);
int top (STACK *s, int *x);

#endif

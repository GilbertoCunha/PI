#ifndef _TESTE
#define _TESTE

typedef struct slist {
  int valor;
  struct slist *prox;
} Nodo, *LInt;

LInt fromArray (int v[], int N);

#define BSize 100

typedef struct larray {
  int valores[BSize];
  struct larray *prox;
} *LArrays;

typedef struct stack {
  int sp;
  LArrays lista;
} Stacks;

void initStack (Stack *s);
void push (Stack *s, int x);
int pop (Stack *s, int *x);

typedef struct spares {
  int x, y;
  struct spares *prox;
} Parm, *LPares;

LPares zip (LInt a, LInt b, int *c);

typedef struct no {
  int value;
  struct no *esq, *dir, *pai;
} No, *Tree;

void calculaPais (Tree t);
Tree next (Tree t);

#endif

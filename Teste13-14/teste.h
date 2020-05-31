#ifndef _TESTE
#define _TESTE

typedef struct slist {
  int valor;
  struct slist *prox;
} Nodo, *LInt;

void ShowArray (int v[], int N);
void ShowLInt (LInt l);
LInt fromArray (int v[], int N);

#define BSize 100

typedef struct larray {
  int valores[BSize];
  struct larray *prox;
} *LArrays;

typedef struct stack {
  int sp;
  LArrays lista;
} Stack;

void ShowStack (Stack s);
void initStack (Stack *s);
void push (Stack *s, int x);
int pop (Stack *s, int *x);

typedef struct spares {
  int x, y;
  struct spares *prox;
} Parm, *LPares;

void ShowLPares (LPares l);
LPares zip (LInt a, LInt b, int *c);

typedef struct no {
  int value;
  struct no *esq, *dir, *pai;
} No, *Tree;

void calculaPais (Tree t);
Tree next (Tree t);

#endif

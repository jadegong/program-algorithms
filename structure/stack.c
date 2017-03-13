/*
 * ENV: ubuntu 16.04, clang-3.9
 * Stack basic operations
 */
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 1024
#define DATATYPE int
typedef struct {
    DATATYPE data[MAXSIZE];
    int top;
}SeqStack;

SeqStack *initStack();
int EmptyStack(SeqStack *s);
int PushStack(SeqStack *s, DATATYPE ele);
int PopStack(SeqStack *s, DATATYPE *x);
DATATYPE TopSeqStack(SeqStack *s);

int main() {}

SeqStack *initStack() {
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}
int EmptyStack(SeqStack *s) {
    return s->top == -1 ? 1 : 0;
}
int PushStack(SeqStack *s, DATATYPE ele) {
    if (s->top == MAXSIZE - 1) return 0; /* Stack is full */
    s->top++;
    s->data[s->top] = ele;
    return 1;
}
int PopStack(SeqStack *s, DATATYPE *x) {
    if (EmptyStack(s)) return 0; /* Stack is empty */
    *x = s->data[s->top--];
    return 1;
}
DATATYPE TopSeqStack(SeqStack *s) {}

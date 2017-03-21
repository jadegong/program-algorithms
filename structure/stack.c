/*
 * ENV: ubuntu 16.04, clang-3.9
 * Stack basic operations
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 1024
#define DATATYPE char
typedef struct {
    DATATYPE data[MAXSIZE];
    int top;
}SeqStack;

SeqStack *initStack();
int EmptyStack(SeqStack *s);
int PushStack(SeqStack *s, DATATYPE ele);
int PopStack(SeqStack *s, DATATYPE *x);
DATATYPE TopSeqStack(SeqStack *s);

int main() { // 测试一个最长括号匹配长度
    char str[MAXSIZE];
    int n;
    SeqStack *seqStack;
    while(printf("请输入字符串：") && scanf("%s", str) != EOF) {
        n = strlen(str);
        seqStack = initStack();
        int max = 0;
        int current = 0;
        DATATYPE *x;
        printf("Str length: %d\n", n);
        for (int i = 0; i < n; i++) {
            PushStack(seqStack, str[i]);
        }
        /*PopStack(seqStack, x);*/
        /*printf("Stack top: %c, Start pop...\n", seqStack->data[seqStack->top]);*/
        /*while (EmptyStack(seqStack) == 0) {*/
            /*PopStack(seqStack, x);*/
            /*printf("%c", *x);*/
        /*}*/
        /*printf("\n");*/
        // Not right
        for(int i = 0; i < n; i++) {
            if (str[i] == '(') {
                PushStack(seqStack, str[i]);
            } else if (str[i] == ')') {
                int popRet = PopStack(seqStack, x);
                if (popRet == 1) {
                    current++;
                } else { // 栈空则将当前连续长度置0
                    current = 0;
                }
            }
            if (current > max) {
                max = current;
            }
        }
        printf("最长匹配括号长度为：%d\n", max * 2);
    }
    return 0;
}
// 初始化一个栈
SeqStack *initStack() {
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}
// 判断是否为空栈
int EmptyStack(SeqStack *s) {
    if (s->top == -1) return 1;
    else return 0;
}
// 入栈
int PushStack(SeqStack *s, DATATYPE ele) {
    if (s->top == MAXSIZE - 1) return 0; /* Stack is full */
    s->top++;
    s->data[s->top] = ele;
    return 1;
}
// 出栈
int PopStack(SeqStack *s, DATATYPE *x) {
    if (EmptyStack(s) == 1) {
        return 0; /* Stack is empty */
    }
    else {
        x = &(s->data[s->top]);
        s->top--;
        return 1;
    }
}

// 栈顶元素
DATATYPE TopSeqStack(SeqStack *s) {
    if (EmptyStack(s) == 1) return '\0'; // 栈为空
    return s->data[s->top];
}


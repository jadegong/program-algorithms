/*
 * 描述：打印一个字符串中字符的所有全排列
 */
#include "stdio.h"
#include "string.h"

void swap(char *a, int from, int to);

void CalcAllPermutation(char *perm, int from, int to);

int main() {
    char str[1000];
    char *s;
    while (scanf("%s", str) != EOF) {
        s = str;
        CalcAllPermutation(s, 0, strlen(s) - 1);
    }
    return 0;
}

void swap(char *a, int from, int to) {
    char temp = a[from];
    a[from] = a[to];
    a[to] = temp;
}

void CalcAllPermutation(char *perm, int from, int to) {
    if (to <= 1) {
        return;
    }
    if (from == to) {
        for (int i = 0; i <= to; i++) {
            printf("%c", perm[i]);
        }
        printf("\n");
    }
    else {
        for (int j = from; j <= to; j++) {
            swap(perm, j, from);
            CalcAllPermutation(perm, from + 1, to);
            swap(perm, j, from);
        }
    }
}

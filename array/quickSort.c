/*
 * Quick sort algorithms
 */
#include "stdio.h"
#include "stdlib.h"

void quickSort(int *a, int p, int r);
int quickSortIndex(int *a, int p, int r);
void swap(int *a, int from, int to);

int main() {
    int n;
    int *a;
    while(printf("请输入数组长度：") && scanf("%d", &n) != EOF && n > 0 && printf("请输入数组元素(空格分隔)：\n")) {
        a = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", (a + i));
        }
        quickSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", *(a + i));
        }
        printf("\n");
    }
    free(a);
    return 0;
}

void quickSort(int *a, int p, int r) {
    if (p < r) {
        int q = quickSortIndex(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int quickSortIndex(int *a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, r);
    return i + 1;
}

void swap(int *a, int from, int to) {
    int temp = a[from];
    a[from] = a[to];
    a[to] = temp;
}

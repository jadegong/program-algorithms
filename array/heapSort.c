/*
 * ENV: ubuntu 16.04, clang-3.9
 * 堆排序算法
 */
#include "stdio.h"
#include "stdlib.h"

void heapSort(int *a, int n);
void heapSortIndex(int *a, int n, int i);
void buildMaxHeap(int *a, int n);
void swap(int *a, int from, int to);

int main() {
    int n;
    int *a;
    while(printf("请输入数组长度：") && scanf("%d", &n) != EOF && printf("请输入数组元素(空格分隔)：\n")) {
        a = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", (a + i));
        }
        heapSort(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", *(a + i));
        }
        printf("\n");
    }
    free(a);
    return 0;
}

void heapSort(int *a, int n) {
    if (n < 2) return;
    buildMaxHeap(a, n);
    int heapSize = n;
    for (int i = n - 1; i > 0; i--) {
        swap(a, 0, i);
        heapSize--;
        heapSortIndex(a, heapSize, 0);
    }
}

void heapSortIndex(int *a, int n, int i) {
    int l = ((i + 1) << 1) - 1, r = (i + 1) << 1;
    int largest = i;
    if (l < n && a[l] > a[i]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a, i, largest);
        heapSortIndex(a, n, largest);
    }
}

// build maximum heap
void buildMaxHeap(int *a, int n) {
    // 自底向上对每一层进行heapSortIndex操作
    for (int j = (n >> 1) - 1; j >= 0; j--) {
        heapSortIndex(a, n, j);
    }
}

void swap(int *a, int from, int to) {
    int temp = a[from];
    a[from] = a[to];
    a[to] = temp;
}

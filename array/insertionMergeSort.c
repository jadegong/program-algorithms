/*
 * ENV: ubuntu 16.04, clang-3.9
 * 插入和归并排序算法
 */
#include "stdio.h"
#include "stdlib.h"
#include "limits.h" /*提供INT_MAX等常量*/

void InsertionSort(int *a, int n);
void MergeSlice(int *a, int p, int q, int r);
void MergeSort(int *a, int p, int r);

int main() {
    int len, i;
    int *a;
    while (printf("请输入数组长度：") && scanf("%d", &len) != EOF && len > 0) {
        a = (int*)malloc(len * sizeof(int));
        printf("请输入数组元素(空格分开)：\n");
        for (i = 0; i < len; i++) {
            scanf("%d", (a + i));
        }
        /*InsertionSort(a, len);*/
        MergeSort(a, 0, len - 1);
        for (i = 0; i < len; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    free(a);
    return 0;
}

// 插入排序
void InsertionSort(int *a, int n) {
    for (int j = 1; j < n; j++) {
        int temp = a[j];
        // Insert a[j] to a[0...j-1]
        int i = j - 1;
        while (i >= 0 && a[i] > temp) { //交换条件
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = temp;
    }
}

// 归并排序时归并的过程
void MergeSlice(int *a, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[1024], R[1024], i, j;
    for (i = 0; i < n1; i++) {
        L[i] = a[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[q + j + 1];
    }
    /*不使用边界值（哨兵）*/
    /*L[n1] = INT_MAX;*/
    /*R[n2] = INT_MAX;*/
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++) {
        if (i >= n1) { // 左边界
            a[k] = R[j];
            j++;
            continue;
        }
        if (j >= n2) { // 右边界
            a[k] = L[i];
            i++;
            continue;
        }
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }
}

// 归并排序
void MergeSort(int *a, int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        MergeSlice(a, p, q, r);
    }
}

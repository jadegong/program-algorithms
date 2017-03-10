/*
 * ENV: ubuntu 16.04, clang-3.9
 * 查找和最大子数组
 * 1.分治归并O(n * log n)
 * 2.线性查找O(n)
 */
#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

// 返回结构体
struct MaximumRet{
    int l; // 最大子数组开始处
    int r; // 最大子数组结束处
    int s; // 最大子数组和
};

struct MaximumRet findMaxCrossingSubarray(int *a, int low, int mid, int high);
struct MaximumRet findMaximumSubarray(int *a, int low, int high);
struct MaximumRet findMaximumSubarrayBest(int *a, int n);

int main() {
    int n;
    int *a; 
    while (printf("请输入数组长度：") && scanf("%d", &n) != EOF && n > 0) {
        a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", (a + i));
        }
        /*struct MaximumRet ret = findMaximumSubarray(a, 0, n - 1);*/
        struct MaximumRet ret = findMaximumSubarrayBest(a, n);
        printf("从第%d个到第%d个和最大为%d\n", ret.l + 1, ret.r + 1, ret.s);
        free(a);
    }
    return 0;
}

// 跨越中间的最大子数组
struct MaximumRet findMaxCrossingSubarray(int *a, int low, int mid, int high) {
    int ls = INT_MIN, rs = INT_MIN, sum = 0, ml, mr;
    struct MaximumRet ret;
    for (int i = mid; i >= low; i--) {
        sum = sum + a[i];
        if (sum > ls) {
            ls = sum;
            ml = i;
        }
    }
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum = sum + a[j];
        if (sum > rs) {
            rs = sum;
            mr = j;
        }
    }
    ret.l = ml;
    ret.r = mr;
    ret.s = ls + rs;
    return ret;
}

// 最大子数组 -> O(n * log n)
struct MaximumRet findMaximumSubarray(int *a, int low, int high) {
    struct MaximumRet ret1, ret2, ret3, ret = {low, high, a[low]};
    if (low == high) {
        return ret; // base case; only one element
    }
    else {
        int mid = (low + high)/2;
        ret1 = findMaximumSubarray(a, low, mid);
        ret2 = findMaximumSubarray(a, mid + 1, high);
        ret3 = findMaxCrossingSubarray(a, low, mid, high);
        if (ret1.s >= ret2.s && ret1.s >= ret3.s) {
            return ret1;
        }
        else if (ret2.s >= ret1.s && ret2.s >= ret3.s) {
            return ret2;
        }
        else {
            return ret3;
        }
    }
}

// O(n)
struct MaximumRet findMaximumSubarrayBest(int *a, int n) {
    struct MaximumRet ret = {0, 0, a[0]};
    int sum = a[0], b = 0, left = 0;
    for (int i = 0; i < n; i++) {
        if (b < 0) {
            b = a[i];
            left = i;
        } else {
            b = b + a[i];
        }
        if (b > sum) {
            sum = b;
            ret.l = left;
            ret.r = i;
        }
    }
    ret.s = sum;
    return ret;
}

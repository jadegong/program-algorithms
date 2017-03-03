/*
 * 描述：判断字符串是否为回文串
 */
#include "stdio.h"
#include "string.h"
#include "stdbool.h" //引入bool类型

bool IsPalidromeFromSide(char *s);
bool IsPalidromeFromMid(char *s);

int main() {
    char str[128];
    char *s;
    while (scanf("%s", str) != EOF) {
        s = str;
        printf("Result: %d\n", IsPalidromeFromMid(s));
    }
    return 0;
}

/*
 * 从两边往中间比
 */
bool IsPalidromeFromSide(char *s) {
    if (s == 0) {
        return false;
    }
    for (int i = 0; i < strlen(s)/2; i++) {
        if (s[i] != s[strlen(s) - i - 1]) {
            return false;
        }
    }
    return true;
}

/*
 * 从中间往两边比，用两个指针
 */
bool IsPalidromeFromMid(char *s) {
    if (s == 0) {
        return false;
    }
    char *first, *second;
    int m = ((strlen(s) >> 1) -1) >= 0 ? ((strlen(s) >> 1) - 1) : 0;
    first = s + m;
    second = s + strlen(s) -1 - m;
    while (first >= s) {
        if (*first != *second) {
            return false;
        }
        --first;
        ++second;
    }
    return true;
}

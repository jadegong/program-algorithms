/*
 * ENV: ubuntu 16.04, clang-3.9
 * 描述：给一个字符串，求它的最长回文子串的长度
 */
#include "stdio.h"
#include "string.h"

#define min(x, y) (x > y ? y : x)

int LongestPalindromeEnum(char *s, int n);
int LongestPalindromeManacher(char *s, int n);

int main() {
    char str[1024];
    char *s;
    int n;
    while (scanf("%s", str) != EOF) {
        s = str;
        n = strlen(str);
        printf("最长回文串长度：%d\n", LongestPalindromeManacher(s, n));
    }
    return 0;
}

// 枚举每一个中心点，向两边扩展
int LongestPalindromeEnum(char *s, int n) {
    if (s == 0 || n < 1) {
        return 0;
    }
    int i, j, c, max = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; (i - j >= 0) && (i + j < n); ++j) { // palindrome length odd case
            if (s[i - j] != s[i + j]) {
                break;
            }
            c = j * 2 + 1;
        }
        if (c > max) {
            max = c;
        }
        for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j) { // palindrome length even case
            if (s[i - j] != s[i + j + 1]) {
                break;
            }
            c = j * 2 + 2;
        }
        if (c > max) {
            max = c;
        }
    }
    return max;
}

// manacher方法解决
int LongestPalindromeManacher(char *s, int n) {
    if (s == 0 || n < 1) {
        return 0;
    }
    int i;
    // 处理字符串
    for (i = 2 * strlen(s) + 2; i >= 0; --i) {
        if (i == 0) {
            s[i] = '$';
            continue;
        }
        if (i%2 == 0) {
            s[i] = s[i/2 - 1];
        }
        else {
            s[i] = '#';
        }
    }
    int p[1000], mx = 0, id = 0, ret;
    memset(p, 0, sizeof(p));
    for (i = 0; s[i] != '\0'; i++) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (s[i + p[i]] == s[i - p[i]]) {
            p[i]++;
        }
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
            ret = p[i] - 1;
        }
    }
    return ret;
}

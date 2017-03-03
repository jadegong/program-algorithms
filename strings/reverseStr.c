/*
 * 题目描述
 * 给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，使得原字符串变成字符串“cdefab”。请写一个函数完成此功能，要求对长度为n的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。
 */
/*
 * 思路：将字符串分为两部分，先各自翻转然后整体翻转
 */
#include "stdio.h"
#include "string.h"

void LeftRotateString(char *s, int n, int m);

int main() {
    char s[] = "123456"; /*使用char *直接赋值时，不能更改字符串中的字符*/
    char *str = s;
    int len = strlen(s), m = 3;
    LeftRotateString(str, len, m);
    printf("Result: %s\n", str);
    return 0;
}

/*
 * 翻转字符串一部分
 */
void ReverseString(char *s, int from, int to) {
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

/*
 * 实现方法
 */
void LeftRotateString(char *s, int n, int m) {
    printf("In left rotate: %s, %d, %d\n", s, n, m);
    m %= n;
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n - 1);
}


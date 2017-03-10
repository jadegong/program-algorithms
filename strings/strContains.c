/*
 * ENV: ubuntu 16.04, clang-3.9
 * 题目描述：给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。
 * 请问，如何最快地判断字符串B中所有字母是否都在字符串A里？为了简单起见，我们规定输入的字符串只包含大写英文字母
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h" /*引入bool*/

bool StringContainViolent(char *a, char *b);
bool StringContainSort(char *a, char *b);
bool StringContain(char *a, char *b);

/*升序*/
int compi(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}
/*降序*/
int compd(const void *a, const void *b) {
    return *(char*)b - *(char*)a;
}

int main() {
    char a[128], b[128]; /*scanf接收char数组*/
    char *astr;
    char *bstr;
    while(scanf("%127s%127s", a, b) != EOF) {
        astr = a;
        bstr = b;
        printf("Contains: %d\n", StringContain(astr, bstr));
    }
    return 0;
}

/*
 * 暴力破解，双重循环；O(m*n)
 */
bool StringContainViolent(char *a, char *b) {
    for (int i = 0; i < strlen(b); i++) {
        int j;
        for (j = 0; (j < strlen(a) && a[j] != b[i]); ++j) /*意思为有相等的就break*/
            ;
        if (j >= strlen(a)) { /*其中有一个字符没找到*/
            return false;
        }
    }
    return true;
}

/*
 * 通过快速排序后，再寻找；O(m*log m)+O(n*log n) 和 O(m+n)之间
 */
bool StringContainSort(char *a, char *b) {
    //sort first
    qsort(a, strlen(a), sizeof(a[0]), compi);
    qsort(b, strlen(b), sizeof(b[0]), compi);
    printf("After sort: a=%s, b=%s\n", a, b);
    for (int pa = 0, pb = 0; pb < strlen(b);) {
        while ((pa < strlen(a)) && (a[pa] < b[pb])) { //从a中查找第一个相等的
            ++pa;
        }
        if (pa >= strlen(a) || (a[pa] > b[pb])) { // 当前字符在a中没找到
            return false;
        }
        //a[pa] == b[pb]时
        ++pb;
    }
    return true;
}

/*
 * 最佳方法：位运算，每个字符减去'A'结果ret，1 << ret，那么不同字母对应的左移位数不同，
 * 然后a串中所有左移后做或运算，得到一个数，然后与每个b中字符左移结果进行与运算，为0则false
 * O(m+n), 空间O(1)
 */
bool StringContain(char *a, char *b) {
    int aret = 0;
    for (int i = 0; i < strlen(a); i++) {
        aret |= (1 << (a[i] - 'A')); // 每一个字母对应唯一的位
    }
    for (int i = 0; i < strlen(b); i++) {
        if ((aret & (1 << (b[i] - 'A'))) == 0) { // b中每个字符对应位是否为1
            return false;
        }
    }
    return true;
}

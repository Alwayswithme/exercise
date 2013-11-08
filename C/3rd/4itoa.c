/**
 * 在数的对二的补码表示中,我们编写的itoa函数不能处理最大的负数,即n等于-(2^(字长-1))
 * 的情况.请解释其原因.修改该函数, 使它在任何机器上运行时都能打印出正确的值
 */
#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x) : (x));
void itoa(int n,char s[]);

void reverse(char s[]);

int main() {
}

/* itoa: convert n to characters in s  */

void itoa(int n,char s[]) {
    int i, sign;

    sign = n;       /* record sign */
    i = 0;
    do {            /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';     /* get next digit */
    }while ((n /= 10) != 0);            /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

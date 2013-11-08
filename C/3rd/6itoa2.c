/**
 * 修改itoa函数,使得该函数可以接收三个参数.其中,第三个参数为最小字段
 * 为了保证转换后所得到的结果至少具有第三个参数指定的最小宽度,在必要
 * 时应在所得结果的左边填充一定的空格.
 */
#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x) : (x));
void itoa(int n,char s[], int w);

void reverse(char s[]);

int main() {
}

/* itoa: convert n to characters in s  */

void itoa(int n,char s[], int w) {
    int i, sign;

    sign = n;       /* record sign */
    i = 0;
    do {            /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';     /* get next digit */
    }while ((n /= 10) != 0);            /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while (i < w) {                    /* pad with blanks */
        s[i++] = ' ';
    }
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

int trim(char s[]) {
    int n; 
    for (n = strlen(s) - 1; n >= 0; n--) 
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}

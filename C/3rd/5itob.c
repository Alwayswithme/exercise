/**
 * 编写函数itob(n, s, b), 将整数n转换为以b为底的数,并将转换结果以字符
 * 的形式保存到字符串s中.例如, itob(n, s, 16)把整数n格式化成十六进制整数
 * 保存在s中.
 */

#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0? -(x):(x));
void itob(int n, char s[], int b);

void reverse(char s[]);

int main() {
    char s[100];
    itob(-10, s, 8);
    puts(s);
}
void itob(int n, char s[], int b) {
    int j, i, sign;
    sign = n;           /* record sign */
    i = 0;
    do {
        j = abs(n % b); /* get next digit */
        s[i++] = (j <= 9) ? j + '0': j + 'a' - 10;
    } while (( n/=b ) != 0);    /* delete it */
    if ( sign < 0 )
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

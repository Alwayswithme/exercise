/**
 * 运用printd函数的设计思想编写一个递归版本的itoa函数,即通过
 * 递归调用把整数转换为字符串.
 */
#include <math.h>

int main() {}

/* itoa: convert n to characters in s; recursive */
void itoa(int n, char s[]) {
    static int i;
    if (n / 10)
        itoa(n/10, s);
    else {
        i = 0;
        if ( n < 0 )
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

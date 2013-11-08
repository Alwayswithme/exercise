/**
 * 编写一个将输入复制到输出的程序，并将其中多个连续的
 * 空格用一个空格代替
 */
#include <stdio.h>

#define NONBLANK 'a'
main() {
    int c, lastc;
    lastc = NONBLANK;
    while ( (c = getchar()) != EOF) {
        if ( c != ' ')
            putchar(c);
        else if ( lastc != ' ')
            putchar(c);
        lastc = c;
    }
}

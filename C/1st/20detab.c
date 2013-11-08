/**
 * 编写程序detab，将输入中的制表符替换成适当数目的空格，使空格
 * 充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定
 * 的，比如每个n列就会出现一个制表符终止位。n应该作为变量还是符号
 * 常量？
 */
#include <stdio.h>

#define TABINC 8        /* tab increment size   */

int main(void) {
    int c, nb, pos;
    nb = 0;     /* number of blanks necessary */
    pos = 1;    /* position of character in line */

    while ((c = getchar()) != EOF) {
        if (c == '\t') {            /* tab character  */
            nb = TABINC - (pos - 1) % TABINC;
            while ( nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if ( c == '\n') { /* newline character */
            putchar(c);
            pos = 1;
        } else {                    /* other character */
            putchar(c);
            ++pos;
        }
    }
}

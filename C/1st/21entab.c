/**
 * 编写程序entab，将空格替换为最少数量的制表符和空格，但要保持单词之间
 * 的间隔不变。假设制表符终止位的位置于练习1-20的detab程序的情况相同。
 * 当使用一个制表符或一个空格都可以到达下一个制表符终止位时，选用那种
 * 替换字符比较好？
 */
#include <stdio.h>

#define TABINC 8

int main() {
    int c, nb, nt, pos;
    nb = nt =0;             /* number of blanks and tabs necessary */
    for (pos = 1; (c = getchar()) != EOF; ++pos) {
        if ( c == ' ' ) {
            if ( pos % TABINC != 0 )
                ++nb;       /* increment number of blanks */
            else {
                nb = 0;     /* reset number of blanks     */
                ++nt;       /* on more tab      */
            }
        } else {
            for ( ; nt > 0; --nt)
                putchar('\t');      /* output tab(s) */
            if (c == '\t')          /* forget the blanks */
                nb = 0;
            else                    /* output blanks   */
                for ( ; nb > 0; --nb)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if ( c == '\t' )
                pos = pos + (TABINC - ( pos - 1 ) % TABINC) - 1;
        }
    }
}

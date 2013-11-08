/**
 * 编写一个程序，打印输入中单词长度的直方图。
 * 水平方向的直方图比较容易绘制，垂直方向的
 * 直方图则要困难些
 */
#include <stdio.h>

#define MAXHIST 15    /* max length of histogram */
#define MAXWORD 11    /* max length of a word    */
#define IN      1     /* inside a word           */
#define OUT     0     /* outside a word          */

main() {
    int c, i, nc, state;
    int len;                /* length of bar  */
    int maxvalue;           /* maximum value for wl[] */
    int overflow;           /* number of overflow words  */
    int wl[MAXWORD];        /* word length counters */

    /* initialize */
    state = OUT;
    nc = 0;
    overflow = 0;
    for ( i = 0; i < MAXWORD; i++)
        wl[i] = 0;
    maxvalue = 0;
    /* initialize */

    /*
     * read char from stdinput
     */
    while (( c = getchar() ) != EOF) {
        if ( c == ' ' || c == '\t' || c == '\n' ) {
            state = OUT;
            if (nc > 0)
                if ( nc < MAXWORD )
                    ++wl[nc];
                else
                    ++overflow;
            nc = 0;
        } else if ( state == OUT ) {
            state = IN;
            nc = 1;         /* beginning of a new word */
        } else
            ++nc;           /* inside a word */
    }

    /* calculate the max value */
    for ( i = 1; i < MAXWORD; ++i)
        if ( wl[i] > maxvalue)
            maxvalue = wl[i];


    /* draw the bar horizontally in stdoutput */
    for ( i = 1; i < MAXWORD;++i) {
        printf("%5d - %5d : ", i, wl[i]);
        if ( wl[i] > 0 ) {
            if (( len = wl[i] * MAXHIST / maxvalue ) <= 0)
                len = 1;
        } else
            len = 0;
        while ( len > 0 ) {
            putchar ('*');
            --len;
        }
        putchar('\n');
    }
    if (overflow  > 0 )
        printf(" There are %d words >= %d\n", overflow, MAXWORD);
}

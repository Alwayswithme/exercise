#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0

int main() {
    int c,i, nc, state;
    int len;
    int maxvalue;
    int overflow;
    int wl[MAXWORD];

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

    /* draw the bar vertically in stdoutput */
    for (i = MAXHIST; i > 0; --i) {
        for (int j = 1; j < MAXWORD; ++j)
            if ( wl[j] * MAXHIST / maxvalue >= i)
                printf("  *  ");
            else
                printf("     ");
        putchar('\n');
    }

    for (i = 1; i < MAXWORD; ++i) 
        printf("%4d ", i);
    putchar('\n');
    for ( i = 1; i < MAXWORD; ++i)
        printf("%4d ", wl[i]);
    putchar('\n');
    if (overflow > 0)
        printf (" There are %d words >= %d\n", overflow, MAXWORD);
    return 0;
}

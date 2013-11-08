/**
 * 编写一个程序，以每行一个单词的形式打印其输入
 */
#include <stdio.h>

#define IN 0
#define OUT 1
main() {
    int state,c;
    state = OUT;
    while (( c = getchar() ) != EOF) {
        if ( c == '\t' || c == '\n' || c == ' ') {
            if ( state == IN) {   /*  finish the word */
                state = OUT;
                printf("\n");
            }
        } else if (state == OUT) {
            state = IN;           /* beginning of word */
            putchar(c);
        } else                    /* inside a word  */
            putchar(c);
    }
}

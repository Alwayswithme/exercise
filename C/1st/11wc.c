/**
 *  测试边界条件：
 *  没有输入
 *  没有单词,只有换行符
 *  只有空格、制表符和换行符
 *  每个单词各占一行
 *  单词出现文本行行首
 *  单词出现于一串空格之后的情况
 */
#include <stdio.h>

#define IN 1 /* inside the word */
#define OUT 0 /* outside the word */

main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc =0;
    while (( c = getchar()) != EOF) {
        ++nc; /* char count ++ */
        if ( c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("word%s: %d\n", nw == 1? "":"s", nw);
    printf("line%s: %d\n", nl == 1? "":"s", nl);
    printf("char%s: %d\n", nc == 1? "":"s", nc);
}

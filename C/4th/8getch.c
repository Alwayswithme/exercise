/*
 * 假定最多智能压回一个字符.请相应的修改getch于
 * ungetch这两个函数
 */
#include <stdio.h>
char buf = 0;

/* getch: get a (possibly pushed back) character */
int getch(void) {
    int c;
    (buf != 0)? c = buf: c = getchar();
    buf = 0;
    return c;
}

/* ungetch: push character back onto the input */
void ungetch(int c) {
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}

#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int buf[BUFSIZE];  /* 用于ungetch函数的缓冲区 */
int bufp = 0;       /* buf 中下一个空闲位置    */

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch:  push back a character to buf */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets: push back an entire string onto input*/
void ungets(char *s) {
    int len = strlen(s);
    while( len > 0 )
        ungetch(s[--len]);
}

/*
 * 在上面的例子中,如果符号+或-的后面紧跟的不是数字,getint函数将把符号视为
 * 数字0的有效表达式.修改该函数,将这种形式的+或-符号重新压回输入缓冲区.
 */
#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(int *pn) {
    int c, d, sign;
    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-')? -1 : 1;
    if (c == '+' || c == '-') {
        d = c;                      /* remember sign char */
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);         /* push back non-digit */
            ungetch(d);             /* push back sign char */
            return d;               /* return sign char */
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) 
        printf("ungetch : too many character\n");
    else
        buf[bufp++] = c
}

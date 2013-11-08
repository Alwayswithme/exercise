/*
 * 模仿函数getint的实现方法, 编写一个读取浮点数的函数
 * getfloat. getfloat函数的返回值应该时什么类型?
 */
#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(float *pn) {
    int c, d, sign;
    float power;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);                 /* it's not a number */
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
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');   /* integer part */
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');   /* fractional part */
        power *= 10.0;
    }
    *pn *= sign/power;                  /* final number */
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

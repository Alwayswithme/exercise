/**
 * 给计算器程序增加访问sin,  exp与pow等库函数的操作.
 * 有关这些库函数的详细信息, 参见附录B5.4节中的头文件
 * <math.h>
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

/* getop函数: 获取下一个运算符或数值操作符 */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') /* skip white space */
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c)) { /* command or NAME */
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);     /* went one char too far */
        if (strlen(s) > 1)
            return NAME;    /* >1 char; it is NAME */
        else
            return s[0];       /* it may be a command */
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;           /* not a number */
    if (c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';     /* minus sign */
        }
    if (isdigit(c))         /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')           /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/**
 * 另一种方法是通过getline函数读入整个输入行,这种情况下可以
 * 不使用getch与ungetch函数. 请运用这一方法修改计算器程序
 */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
int getline(char line[], int limit);
int li = 0;
char line[MAXLINE];


/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int c, i;
    if (line[li] == '\0')
        if (getline(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;
    while ((s[0] = c= line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}

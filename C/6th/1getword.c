/**
 * 上述getword函数还不能正确处理下划线、字符串常数、注释及预编译控制指令。
 * 请编写一个更完善的getword函数
 */
#include <stdio.h>
#include <ctype.h>

void ungetch(int);
int getch(void);
/* getword: get next word or character form input */
int getword(char *word, int lim) {
    int c, d, comment(void);
    char *w = word;
    while (isblank(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {
        for ( ; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
    } else if (c == '\'' || c == '"') {
        for ( ; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF)
                break;
    } else if (c == '/')
        --w;
        if ((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    *w = '\0';
    return c;
}
/* comment: skip over comment and return a character */
int comment(void) {
    int c;
    while((c = getch()) != EOF)
        if (c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
    return c;
}

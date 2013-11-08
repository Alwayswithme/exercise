/**
 * 编写一个程序，删除每个输入行末尾的空格和制表符，并删除完全时空格的行
 */
#include <stdio.h>
#define MAXLINE 1000     /* maximum input line size */

int rline(char line[], int maxline);

int trail(char s[]);

/* remove trailing blanks and tabs, and delete blank lines */
int main() {
    char line[MAXLINE];     /* curreent input line */
    while ( rline(line, MAXLINE) > 0 )
        if (trail(line) > 0)
            printf("%s", line);
    return 0;
}

int rline(char s[], int lim) {
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        if (i < lim - 2)
            s[i] = c;
    if ( c == '\n' ) {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

int trail(char s[]) {
    int i;
    i = 0;
    while ( s[i] != '\n')       /* find newline character */
        ++i;
    --i;                        /* back off from '\n'     */
    while ( i >= 0 && ( s[i] == ' ' || s[i] == '\t'))
        --i;
    if ( i >= 0 ) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}      

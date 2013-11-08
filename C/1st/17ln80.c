/**
 * 打印长度大于80个字符的所有输入行
 */
#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int getlines(char line[], int maxline);

int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line  */

    while ((len = getlines(line, MAXLINE)) > 0)
            if (len > LONGLINE)
                printf("%s", line);
    return 0;
}

int getlines(char s[], int lim) {
    int c,i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        if ( i < lim - 2)
            s[i] = c;
    if ( c == '\n' ) {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/**
 * 编写一个程序，删除每个输入行末尾的空格和制表符，并删除完全时空格的行
 */
#include <stdio.h>
#define MAXLINE 1000     /* maximum input line size */

int rline(char line[], int maxline);

int reverse(char s[]);

/* reverse input lines, a line at a time*/
int main() {
    char line[MAXLINE];     /* curreent input line */
    while ( rline(line, MAXLINE) > 0 )
        if (reverse(line) > 0)
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

int reverse(char s[]) {
    int i = 0, j = 0;
    while (s[i] != '\0')        /* find the end of string  */
        ++i;
    --i;                        /* back off from '\0'       */
    if ( s[i] == '\n' )
        --i;                    /* leave newline in place  */
    while ( j < i ) {
        s[j] = s[j]^s[i];
        s[i] = s[j]^s[i];
        s[j] = s[j]^s[i];
        --i;
        ++j;
    }
}

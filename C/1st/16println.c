/**
 * 修改打印最长文本行的程序的主程序main， 使之可以打印任意长度的输入行的
 * 长度，并尽可能多地打印文本
 */
#include <stdio.h>

#define MAXLINE 1000

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while (( len = getlines(line, MAXLINE)) > 0) {
        printf("%d, %s",len, line); 
        if ( len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getlines(char s[], int lim) {
    int c, i;
    for ( i = 0; (c = getchar()) !=EOF && c != '\n'; ++i)
        if (i < lim - 2) {      /*  line still in boundaries */
            s[i] = c;
        }
    if ( c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy (char to[], char from[]) {
    int i = 0;
    while (( to[i] = from[i]) != '\0' )
        ++i;
}

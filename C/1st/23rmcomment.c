/**
 * 编写一个删除C语言程序中所有的注释语句.要正确处理带引号的字符串与字符常量
 * 在C语言程序中,注释不允许嵌套
 */
#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quota(int c);

/*  remove all comments from a valid C program  */
int main() {
    int c, d;
    while ((c = getchar()) != EOF)
        rcomment(c);
    return 0;
}

/*  rcomment: read each character, remove the comments  */
void rcomment(int c) {
    int d;
    if (c == '/') {
        if ((d = getchar()) == '*')
            in_comment();       /* beginning comment */
        else if (d == '/') {
            putchar(c);         /* another slash    */
            rcomment(d);
        } else {
            putchar(c);         /* not a comment    */
            putchar(d);
        }
    } else if (c == '\'' || c == '"')
        echo_quota(c);          /* quota begins */
    else
        putchar(c);             /* not a comment */
}

/* in_comment: inside of a valid comment        */
void in_comment(void) {
    int c, d;
    c = getchar();              /* prev character   */
    d = getchar();              /* curr character   */
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

/* echoa_quota: echo characters within quotes       */
void echo_quota(int c) {
    int d;

    putchar(c);
    while ((d = getchar()) != c) {  /* search for end   */
        putchar(d);
        if (d == '\\')
            putchar(getchar());     /* ignore escape seq */
    }
    putchar(d);
}

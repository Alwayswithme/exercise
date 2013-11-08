/**
 * 编写一个程序,查找C语言程序中的基本语法错误,如圆括号、方括号以及花括号
 * 不配对等.要正确处理引号(包括单引号、双引号)、转义字符序列与注释。
 * (如果读者想把该程序编写成完全通用的程序，难度会比较大。)
 */
#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

/* rudimentary syntax checker fo C programs */
int main() {
    int c;
    extern int brace,brack,paren;
    while ((c =getchar()) != EOF) {
            if (c == '/') {
                if ((c = getchar()) == '*')
                    in_comment;     /* inside comment   */
            } else if (c == '\'' || c == '"')
                    in_quote(c);
            else
                search(c);

            if ( brace < 0) {
                printf("Unbalanced braces\n");
                brace = 0;
            } else if ( brack < 0 ) {
                printf("Unbalanced brackets\n");
                brack = 0;
            } else if ( paren < 0 ) {
                printf("Unbunlanced parentheses\n");
                paren = 0;
            }
    }
    if (brace > 0)
        printf("Unbalanced braces\n");
    if (brack > 0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses\n");
}

/* search: search for rudimentary syntax errors */
void search (int c) {
    extern int brace, brack, paren;
    if (c == '{')
        ++brace;
    else if (c == '}')
        --brace;
    else if (c == '[')
        ++brack;
    else if (c == ']')
        --brack;
    else if (c == '(')
        ++paren;
    else if (c == ')')
        --paren;
}

/* in_comment: inside of a valid comment        */
void in_comment(void) {
    int c, d;
    c = getchar();              /* prev character   */
    d = getchar();              /* curr character   */
    while (c != '*' || d != '/') { /* search for end */
        c = d;
        d = getchar();
    }
}

/* in_quote: inside quote */
void in_quote(int c) {
    int d;
    while ((d = getchar()) != c) /* search end quote */
            if ( d == '\\' )
                getchar();      /* ignore escape seq */
}

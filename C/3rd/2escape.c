/**
 * 编写一个函数escape(s, t), 将字符串t复制到字符串s中,并在复制过程中将换行符,
 * 制表符等不可显示字符分别转换为\n, \t等相应的可显示的转义字符序列.要求使用
 * switch语句.再编写一个具有相反功能的函数,在复制过程中将转义字符序列转换为实际
 * 字符
 */
#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int main() {
}
/* escapse: expand newline and tab into visible sequences while copying the
 * string t to s */

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        switch (t[i]) {
            case '\n':              /* newline          */
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':              /* tab              */
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:                /* all other chars */
                s[j++] = s[i];
                break;
        }
    s[j] = '\0';
}

/* unescape: convert escape sequences into real characters while copyting the
 * string t to s */
void unescape(char s[], char t[]) {
    if ( t[i] != '\\' )
        s[j++] = t[i];
    else
        switch(t[++i]) {
            case 'n':           /* newline */
                s[j++] = '\n';
                break;
            case 't':           /* real tab         */
                s[j++] = '\t';
                break;
            default:            /* all other chars */
                s[j++] = '\\';
                s[j++] = t[i];
                break;
        }
    s[j] = '\0';
}

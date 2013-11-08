/*
 * 编写一个函数ungets(s), 将整个字符串s压回到输入中
 */
#include <string.h>

/* ungets: push string back onto the input */
void ungets(char s[]) {
    int len = strlen(s);
    void ungetch(int);

    while (len > 0)
        ungetch(s[--len]);
}

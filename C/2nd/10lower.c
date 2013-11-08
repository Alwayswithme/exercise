/**
 * 重新编写将大写字母转换为小写字母的函数lower,并用条件表达式替代其中的if-elsejiegou
 */
#include <stdio.h>

int lower(int c);
int main() {
}
/* lower: convert c to lower case (ASCII only) */
int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

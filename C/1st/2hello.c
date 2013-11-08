/**
 * 当printf函数的参数字符串包含\c（c是转移字符序列中未列出的某一个字符）
 * 时，观察会出现什么情况
 */
#include <stdio.h>
main() {
	printf("hello, world\n");
	printf("hello, world\7 \? \y \c");
    /*  \7 bell
     *  \? ?
     *  \y y 编译警告，未定义
     */
}

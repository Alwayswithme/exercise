/**
 * 在栈操作中添加几个命令, 分别用于不弹出元素的情况下打印栈顶
 * 元素;复制栈顶元素;交换栈顶两个元素的值.另外增加一个命令用于
 * 清空栈
 */
#include <stdio.h>
#include "calc.h"

#define MAXVAL 100  /* 栈val的最大深度 */

int sp = 0;
double val[MAXVAL];

/* push函数: 把f压入栈中 */
void push(double f) {
    if ( sp < MAXVAL )
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop函数: 弹出并返回栈顶的值 */
double pop(void) {
    if ( sp > 0 )
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* clear: clear the stack */
void clear(void) {
    sp = 0;
}

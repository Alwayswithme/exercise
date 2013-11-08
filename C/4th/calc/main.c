/* test 3
 * 在有了基本框架后,对计算器程序扩充就比较简单了.在该程序中加入取模(%)
 * 运算符, 并注意考虑负数的情况.
 */
/* test 4
 * 在操作中添加几个命令,分别用于在不弹出元素的情况下打印栈顶元素;
 * 复制栈顶元素; 交换栈顶两个的值.另外增加一个命令用于清空栈
 */
/* test 5
 * 给计算器程序增加访问sin, exp与pow等库函数的操作
 */
/* test 6
 * 给计算器程序增加处理变量的命令(提供26个具有单个英文字母变量名的
 * 变量). 增加一个变量存放最近打印的值
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <string.h>
#include <math.h>
#include "calc.h"


/* reverse Polish calculator */
int main() {
    int type, var = 0;;
    double op1, op2, v;
    char s[MAXOP];
    double variable[26];

    for (int i = 0; i < 26; i++)
        variable[i] = 0.0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push (atof(s));
                break;
                /*   test 5  */
            case NAME:
                mathfnc(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zere divisor\n");
                break;
                /*  test 3   */
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
                /*   test 4   */
            case '?':       /* printf top element of the stack */
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'c':       /* clear the stack */
                clear();
                break;
            case 'd':       /* duplicate top elem. of the  stack */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':       /* swap the top elements */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
                /* test 5 */
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[var - 'A'] = pop();
                else
                    printf("error: no variable name\n");
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variable[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
        var = type;
    }
    return 0;
}

/* mathfnc : check string s for support math functions */
void mathfnc(char s[]) {
    double op2;
    if (strcmp(s,"sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
}



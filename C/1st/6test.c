/**
 * 验证布尔表达式getchar（）！= EOF 的取值是0还是1.
 */
#include <stdio.h>
main() {
    int c;
    /*  getchar（） ！=EOF 优先级较高，有文件结束符时
     *  c被赋值为0，跳出循环程序结束
     */
    while ( c=getchar() != EOF)
        printf("%d\n", c);
    printf("%d  - at EOF\n", c);
}

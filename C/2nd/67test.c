/**
 * 编写一个函数setbits(x, p, n, y)该函数返回对x执行下列操作后的结果值: 将xzhong从第
 * p位开始的n个(二进制)位设置为y中最右边n位的值,x的其余各位保持不变.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
}

/* setbits: set n bits of x at position p with bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return  ~(~(~0 << n)<<(p-n+1)) & x | (~(~0 << n) & y)<<(p-n+1) ;
}

/**
 * 编写一个函数invert(x, p, n),该函数返回对x执行下列操作后的结果值:将x中第p位开始
 * 的n个(二进制)位求反(即,1变成0,0变成1),x的其余各位保持不变.
 */
unsigned invert(unsigned x, int p, int n) {
    return (~(~0 << n)<<(p-n+1))^x;
}


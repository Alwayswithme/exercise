
/**
 * 编写一个函数rightrot(x, n), 该函数返回将x循环右移(即从最右侧移出的位将从最左端
 * 移入)n(二进制)位后所得到的值.
 */
#include <stdio.h>
unsigned rightrot1(unsigned x, int n);
unsigned rightrot2(unsigned x, int n);
int main() {
    printf("1 right rotation 1 bit is %u\n",rightrot1(1,1));
    printf("2 right rotation 1 bit is %u\n",rightrot1(2,1));
}
/* first version */
unsigned rightrot1(unsigned x, int n) {
    int wordlength(void);
    int rbit;           /* rightmost bit */

    while (n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;     /* shift x 1 position right */
        x = x | rbit;   /* complete one rotation    */
    }
    return x;
}
/* second version */
unsigned rightrot2(unsigned x, int n) {
    int wordlength(void);
    unsigned rbits;

    if ((n = n % wordlength()) > 0) {
        rbits = ~(~0 << n) & x; /* n rightmost bits of x */
                            /* n rightmost bits of left */
        rbits = rbits << (wordlength() - n);
        x = x >> n;         /* x shifted n position right */
        x = x | rbits;      /* rotation complete    */
    }
    return x;
}

/* wordlength : computes word length of the machine */
int wordlength(void) {
    int i = 0;
    unsigned v = (unsigned) ~0;
    while (v != 0) {
        i++;
        v&=(v-1);
    }
    return i;
}

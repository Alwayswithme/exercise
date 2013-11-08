/*
 * 修改温度转换程序，使之能在转换表顶部打印一个标题
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20
main() {
    float fahr, celsius;
    printf ("fahr  Celsius\n");
    for ( fahr = LOWER; fahr <= UPPER; fahr +=STEP) {
        celsius = (5.0 / 9.0) * ( fahr - 32.0 );
        printf( "%3.0f   %6.1f\n", fahr, celsius);
    }
}

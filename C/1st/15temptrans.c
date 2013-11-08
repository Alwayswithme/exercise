/**
 * 重写温度转换程序，使用函数实现温度转换计算
 */
#include <stdio.h>

float transfer (float fahr);
#define LOWER 0
#define UPPER 300
#define STEP  20
main() {
    float fahr, celsius;
    printf ("fahr  Celsius\n");
    for ( fahr = LOWER; fahr <= UPPER; fahr +=STEP) {
        celsius = transfer(fahr);
        printf( "%3.0f   %6.1f\n", fahr, celsius);
    }
}
float transfer (float fahr) {
    int result;
    result =  (5.0 / 9.0) * ( fahr - 32.0 );
    return result;
}

/**
 * 修改温度转换程序，要求以逆序（即按照从300度递减到0度的顺序）
 * 打印温度转换表
 */
#include <stdio.h>

/*
 * print fahr and celsius comparision
 */

#define LOWER 0
#define UPPER 300
#define STEP  20
main() {
    float fahr, celsius;
    printf ("fahr  Celsius\n");
    for ( fahr = UPPER; fahr >= LOWER; fahr -=STEP) {
        celsius = (5.0 / 9.0) * ( fahr - 32.0 );
        printf( "%3.0f   %6.1f\n", fahr, celsius);
    }
}

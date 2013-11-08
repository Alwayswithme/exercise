/**
 * 编写一个程序打印摄氏温度转换为华氏
 * 温度的转换表
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20
main() {
    float fahr, celsius;
    printf ("Celsius   fahr\n");
    for ( celsius = LOWER; celsius <= UPPER; celsius +=STEP) {
        fahr = (9.0 * celsius) /5.0 + 32;

        printf( "%3.0f    %6.1f\n", celsius, fahr);
    }
}

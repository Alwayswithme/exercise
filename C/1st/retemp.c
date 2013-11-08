#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main() {
    float fahr, celsius;

    printf(" This is a title \n");
    for ( celsius = 300; celsius >= 0; celsius -= 20) {
        fahr = celsius * 9.0 / 5.0 + 32;
        printf("%3.0f\t%6.1f\n",celsius, fahr);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

void reverser(char s[], int i , int len );
int main(void) {}

/* reverse : reverse string s in place */
void reverse(char s[]) {
    reverser(s, 0, strlen(s));
}

/* reverser: reverse string s in place: recursive */
void reverser(char s[], int i, int len) {
    int c, j;

    j = len - (i + 1);
    if ( i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}


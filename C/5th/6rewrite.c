/* 采用指针而非数组索引方式改写前面章节和练习中的某些程序,例如getline,
 * atoi, reverse,strindex, getop
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* getline: read a line into s, return length */
int getline(char *s, int lim) {
    int c;
    char *t = s;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/*atoi: convert s to integer; pointer version */
int atoi(char *s) {
    int n, sign;
    for ( ; isspace(*s); s++)
        ;
    sign = (*s == '-'0) ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + *s - '0';
    return sign * n;
}

void reverse(char *);
/* itoa: conver n to character in s; pointer version */
void itoa(int n, char *s) {
    int sign;
    char *t = s;        /* save pointer to s */    
    if ((sign = n) < 0)     /* record sign */
        n = - n;            /* make n positive */
    do {                    /* generate digits in reverse order */
        *s++ = n % 10 + '0';/* get next digit */
    }while ((n  /= 10) > 0);/* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

/* reverse: reverse string s in place */
void reverse(char *s) {
    int c;
    char *t;
    for (t = s + (strlen(s) - 1; s < t; s++, t--)) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
    char *b = s;
    char *p, *r;
    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
            return s-b;
    }
    return -1
}

/* atof : convert string s to double; pointer version */
double atof(char *s) {
    double val, power;
    int sign;
    for ( ; isspace(*s);s++)    /* skip white space */
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    if (power = 1.0; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

/* getop: get next operator or numeric operand; pointer version */
#define NUMBER '0'      /* signal that a number was found */
int getch(void);
void ungetch(int);

int getop(char *s) {
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number  */
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

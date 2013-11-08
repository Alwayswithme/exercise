#include <ctype.h>
#include <string.h>

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

extern int tokentype;   /* type of last token */
extern char token[];    /* last token string */
int prevtoken = NO;     /* there is no previous token */

/* gettoken : return next token */
int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    if ( prevtoken == YES ) {
        prevtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if ( c == '(') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return toketype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c =  getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

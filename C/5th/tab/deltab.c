#include <stdio.h>
#define MAXLINE     100       /* maximum line size */
#define TABINC      0       /* default tab increment size */

#define YES     1
#define NO      0

void settab(int argc, char *argv[], char *tab);;
void detab(char *tab);
int tabpos(int pos, char *tab);

void detab(char *tab) {
    int c, pos = 1;
    while ((c = getchar()) != EOF)
        if (c == '\t') {        /* tab character */
            do
                putchar(' ');
            while(tabpos(pos++, tab) != YES);
        } else if (c == '\n') { /* newline character */
            putchar(c);
            pos = 1;
        } else {                /* all other characters */
            putchar(c);
            ++pos;
        }
}

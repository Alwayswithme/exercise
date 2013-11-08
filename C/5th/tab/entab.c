/*
 * 修改程序entab和detab(第一章练习中编写的函数), 使它们接受一组作为参数的
 * 制表符停止位.如果启动程序时不带参数,则使用默认的制表符停止位位置.
 */
#include <stdio.h>

#define MAXLINE 100     /* maximum line size */
#define TABINC 8        /* default tab increment size */
#define YES    1
#define NO     0


void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

/* replace strings of blanks with tabs */
main(int argc, char *argv[]) {
    char tab[MAXLINE+1];

    settab(argc, argv, tab);        /* initialize tab stops */
    entab(tab);                     /* replace blanks with tab */
    return 0;
}

/* entab: replace strings of blanks with tabs and blanks */
void entab(char *tab) {
    int c, pos;
    int nb = 0;             /* number of blanks necessary */
    int nt = 0;             /* number of tabs necessary */

    for (pos = 1; (c=getchar()) != EOF; pos++)
        if (c == ' ') {
            if (tabpos(pos, tab) == NO)
                ++nb;       /* increment # of blanks */
            else {
                nb = 0;     /* reset # of blanks    */
                ++nt;
            }
        } else {
            for (; nt > 0; nt--)
                putchar('\t');  /* output tabs   */
            if (c == '\t')      /* forget the blanks */
                nb = 0;
            else            /* output blank(s) */
                for (; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos, tab) != YES)
                    ++pos;
        }
}

/*对程序entab和detab做一些扩充,以接受下列缩写的命令:
 * entab -m +n
 * 表示制表符从第m列开始,每隔n列停止.选择(对使用者而言比较方便的默认行为
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100      /* maximum line size */
#define TABINC 8         /* default tab increment size */
#define YES     1
#define NO      0


void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);
/* replace strings of blanks with tabs */
main(int argc, char *argv[]) {
    char tab[MAXLINE+1];
    esettab(argc, argv, tab);       /* initializ tab stops */
    entab(tab);                     /* replace blanks with tab */
    return 0;
}

/* esettab: set tab stops in array tab */
void esettab(int argc, char *argv[], char *tab) {
    int i, inc, pos;
    if (argc <= 1)              /* default tab stop */
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && /* user provided range    */
            *argv[1] == '-' && *argv[2] == '+') {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for ( i = 1; i <= MAXLINE; i++)
            if (i != pos)
                tab[i] = NO;
            else {
                tab[i] = YES;
                pos += inc;
            }
    } else {            /* user provided tab stops */
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO;    /* turn off all tab stops */
        while (--argc > 0) { /* walk through argument list */
            pos = atoi(*++argv);
            if(pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
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

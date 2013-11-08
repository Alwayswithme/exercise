/**
 * 编写一个程序,把较长的输入行"折"成短一些的两行或多行,折行的位置在
 * 输入行的第n列之前的最后一个非空格符之后.要保证程序能够智能地处理输入
 * 行很长以及在指定的列前没有空格或制表符的情况.
 */
#include <stdio.h>

#define MAXCOL 10       /* maximum column of input */
#define TABINC 8        /* tab increment size      */

char line[MAXCOL];      /* input line */

int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */
int main() {
    int c, pos;
    pos = 0;            /* position in the line */

    while(( c = getchar()) != EOF) {
        line[pos] = c;      /* store current character */
        if (c == '\t')
            pos = exptab(pos);  /* expand tab character */
        else if (c == '\n') {
            printl(pos); /* print current input line */
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

/* printl: print line until pos column */
void printl(int pos) {
    int i;
    for (i = 0; i < pos; ++i) 
        putchar(line[i]);
    if (pos > 0)
        putchar('\n');
}

/* exptab: expand tab into blanks       */
int exptab(int pos) {
    line[pos] = ' ';
    for ( ++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)
        return pos;
    else {
        printl(pos);
        return 0;
    }
}
 /* findblank: find blank's position    */
int findblank(int pos) {
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)       /* no blanks in the line ? */
        return MAXCOL;
    else                /* at least on blank */
        return pos+1;   /* positon after the blank */
}

/* newpos: rearrange line with new position */
int newpos(int pos) {
    int i, j;
    if (pos <= 0 || pos >= MAXCOL)
        return 0;       /* nothing to rearrange */
    else {
        i = 0;
        for ( j = pos; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;       /* new position in line */
    }
}


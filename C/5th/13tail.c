/*编写程序tail, 将其输入中的最后n行打印出来.默认情况下,n的值为10,
 * 但可通过一个可选参数改变n的值,因此,命令
 * tail -n将打印其输入的最后n行.无论输入或n的值是否合理,该程序都应该
 * 能正常运行.编写的程序要充分地利用存储空间;输入行的存储方式应该同
 * 5.6节中排序程序的存储方式一样,而不采用固定长度的二维数组
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10     /* default # of line to print */
#define LINES    100    /* max # of lines to print   */
#define MAXLEN   100    /* max length of an input line */

void error(char *);
int getline(char *, int);

/* print last n lines of the input */
main (int argc, char *argv[]) {
    char *p;
    char *buf;                  /* pointer to large buffer */
    char *bufend;               /* end of the buffer        */
    char line[MAXLEN];          /* current input line       */  
    char *lineptr[LINES];       /* pointers to lines read   */
    
    int first, i, last, len, n, nlines;
    if (argc == 1)              /* no argument present      */
        n = DEFLINES;           /* use default # of lines   */
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0] + 1);
    else
        error("usage: tail [-n]");
    if (n < 1 || n > LINES)     /* unreasonable value for n? */
        n = LINES;
    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES * MAXLEN;
    last = 0;                   /* index of last line read  */
    nlines = 0;                 /* number of lines read     */
    while ((len = getline(line, MAXLEN)) > 0) {
        if (p + len + 1 >= bufend)
            p = buf;            /* buffer wrap around       */
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        if (++last >= LINES)
            last = 0;
        p += len + 1;
        nlines++;
    }
    if (n > nlines)             /* req, lines more than rec? */
        n = nlines;
    first = last - n;
    if (first < 0)              /* it did wrap around the list */
        first += LINES;
    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);
    return 0;
}
/* error: print error message and exit  */
void error(char *s) {
    printf("%s\n", s);
    exit(1);
}

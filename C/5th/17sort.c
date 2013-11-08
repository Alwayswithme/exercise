/*
 * 增加字段处理功能,以使得排序程序可以根据行内的不同字段进行排序,
 * 每个字段按照一个单独的选项集合进行排序.(在对本书索引进行排序时,
 * 索引条目使用了-df选型,而对页码排序时使用了-n选项.)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define NUMERIC 1   /* numeric sort */
#define DECR    2   /* sort in decreasing order  */
#define FOLD    4   /* fold upper and lower cases */
#define DIR     8   /* directory order  */
#define LINES   100 /* max of lines to be sorted    */
#define MAXLEN 1000
#define MAXSTR 100

void error(char *);
void readargs(int argc , char *argv[]);
int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void quicksort(char *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int dect);
void swap(void *v[], int, int);


char option = 0;
int pos1 = 0;           /* field beginning with pos1 */
int pos2 = 0;           /* ending just before pos2  */

/* sort input lines */
main (int argc, char *argv[]) {
    char *lineptr[LINES];       /* pointer to text lines    */
    int nlines;                 // number of input lines read
    int rc = 0;

    readargs(argc, argv);
    if ((nlines = readlines(lineptr, LINES)) > 0) {
        if (option & NUMERIC)
            quicksort((void **) lineptr, 0, nlines - 1, (int (*) (void *, void *)) numcmp);
        else
            quicksort((void **) lineptr, 0, 
                    nlines - 1, (int (*) (void *, void *)) charcmp);
        writelines(lineptr, nlines, option & DECR);
    } else {
        printf("input too big to sort \n");
        rc = -1;
    }
    return rc;
}
/* readargs; read program arguments */
void readargs(int argc, char *argv[]) {
    int c;
    int atoi(char *);
    while (--argc > 0 && (c = (*++argv)[0]) == '-'|| c == '+') {
        if (c == '-' && !isdigit(*(argv[0]+1)))
            while (c = *++argv[0])
                switch (c) {
                    case 'd':   // directory order
                        option |= DIR;
                        break;
                    case 'f':   // fold upper and lower cases
                        option |= FOLD;
                    case 'n':   // numeric sort
                        option |= NUMERIC;
                        break;
                    case 'r':   // sort in decreasing order
                        option |= DECR;
                        break;
                    default:
                        printf("sort: illegal option %c\n", c);
                        error("Usage:sort -dfnr [+pos1] [-pos2]");
                        break;
                }
        else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
            error ("Usage: sort -dfnr [+pos1] [-pos2]");
    }
    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}

/* charcmp: return < 0 if s < t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t) {
    char a, b;
    int i, j, endpos;
    extern char option;
    extern int pos1, pos2;
    int fold = (option & FOLD)? 1 : 0;
    int dir = (option & DIR)? 1 : 0;
    i=j=pos1;
    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);
    do {
        if (dir) {
            while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                i++;
            while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                j++;
        }
        if (i < endpos && j < endpos) {
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(s[j]) : s[j];
            j++;
            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);
    return a- b;
}
/* substr: get a substring of s and put str */
void substr(char *s, char *str) {
    int i, j, len;
    extern int pos1, pos2;
    len = strlen(s);
    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        error("substr: string too short");
    for (j = 0, i = pos1; i < len; j++, i++)
        str[j] = s[i];
    str[j] = '\0';
}
/* writelines: write output lines   */
void writelines(char *lineptr[], int nlines, int decr) {
    int i;
    if (decr)       // print in decreasing order
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

/* quicksort */
void quicksort(char *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last - 1, comp);
    quicksort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;
    char str[MAXSTR];
    substr(s1, str );
    v1 = atof(str);
    substr(s2, str );
    v2 = atof(str);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* readlines : read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getli(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* getli: read a line into s, return length */
int getli(char *s, int lim) {
    int c;
    char *t = s;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

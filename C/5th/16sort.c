/*
 * 增加选项-d(代表目录顺序).该选项表明,只对字母,数字和空格进行
 * 比较.要保证该选项可以和-f组合在一起使用.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMERIC 1   /* numeric sort */
#define DECR    2   /* sort in decreasing order  */
#define FOLD    4   /* fold upper and lower cases */
#define DIR     8   /* directory order  */
#define LINES   100 /* max of lines to be sorted    */
#define MAXLEN 1000

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void quicksort(char *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int dect);
void swap(void *v[], int, int);
static char option = 0;

/* sort input lines */
main (int argc, char *argv[]) {
    char *lineptr[LINES];       /* pointer to text lines    */
    int nlines;                 // number of input lines read
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
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
                    argc = 1;
                    rc = -1;
                    break;
            }
    if (argc)
        printf("Usage: sort -dfnr \n");
    else
        if ((nlines = readlines(lineptr, LINES)) > 0) {
            if (option & NUMERIC)
                quicksort((void **) lineptr, 0, nlines - 1, (int (*) (void *, void *)) numcmp);
            else (option & FOLD)
                quicksort((void **) lineptr, 0, nlines - 1, (int (*) (void *, void *)) charcmp);
            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort \n");
            rc = -1;
        }
    return rc;
}

/* charcmp: return < 0 if s < t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t) {
    char a, b;
    int fold = (option & FOLD)? 1 : 0;
    int dir = (option & DIR)? 1 : 0;
    do {
        if (dir) {
            while (!isalnum(*s) && *s != ' ' && *s != '\0')
                s++;
            while (!isalnum(*t) && *t != ' ' && *s != '\0')
                t++;
        }
        a = fold ? tolower(*s) : *s;
        s++;
        b = fold ? tolower(*t) : *t;
        t++;
        if (a == b && a == '\0')
            return 0;
    } while (a == b)
    return a- b;
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

/* numcmp */
int numcmp(char *s1, char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
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

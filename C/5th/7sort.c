/*
 * 重写函数readlines,将输入的文本行存储到由main函数提供的一个数组中
 * 而不是存储到调用alloc分配的存储空间中.
 */
#include <stdio.h>
#include <string.h>

#define MAXLEN 1000     /* maximum length of line */
#define MAXSTOR 50000    /* size of avaiable storage space */
#define MAXLINES 5000

char* lineptr[MAXLINES];
int readlines(char *lineptr[], char *stor, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int getlines(char *, int);

int main() {
    int nlines;
    char a[MAXSTOR];

    if ((nlines = readlines(lineptr, a, MAXLINES)) >= 0 ) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("errof: input too big to sort\n");
        return 1;
    }
}

/* getline: read a line into s, return length */
int getlines(char *s, int lim) {
    int c;
    char *t = s;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while((len = getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p+len > linestop)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* writelines: write lines to stdout */
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


void qsort(char *lineptr[], int left, int right) {
    int last, i;
    if (left >= right)
        return;
    swap(lineptr, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    qsort(lineptr, left, last-1);
    qsort(lineptr, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

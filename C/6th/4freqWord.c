/**
 * 编写一个程序, 根据单词的出现频率按降序打印输入的各个不同单词, 并
 * 在每个单词的前面标上它的出现次数
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD      100
#define NDISTINCT    1000

struct tnode {              /* the tree node; */
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);
struct tnode *talloc(void);

struct tnode *list[NDISTINCT]; /* pointers to tree nodes */
int ntn = 0;                    /* number of tree nodes */

/* print distinct words sorted in descreasing order of freq */
main() {
    struct tnode *root;
    char word[MAXWORD];
    int i;
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treestore(root);
    sortlist();
    for (i = 0; i < ntn; i++)
        printf("%2d:%20s\n", list[i]->count, list[i]->word);
    return 0;
}

/* treestore: store in list[] pointers to tree nodes */
void treestore(struct tnode *p) {
    if (p != NULL) {
        treestore(p->left);
        if (ntn < NDISTINCT)
            list[ntn++] = p;
        treestore(p->right);
    }
}

/* sortlist: sort list of pointers to tree nodes */
void sortlist() {
    int gap, i, j;
    struct tnode *temp;
    for (gap = ntn/2; gap > 0; gap /=2)
        for ( i = gap; i < ntn; i++)
            for (j = i-gap; j >= 0; j -= gap) {
                if ((list[j]->count) >= (list[j+gap]->count))
                    break;
                temp = list[j];
                list[j] = list[j+gap];
                list[j+gap] = temp;
            }
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if(p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

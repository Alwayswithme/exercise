/**
 * 编写一个函数, 它将从由lookup和install维护的表中删除一个变量名及其定义
 */
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];  /* pointer table */
struct nlist {                  /* list item */
    struct nlist *next;         /* next item in list */
    char *name;                 /* define name */
    char *defn;                 /* define text */
};


unsigned hash(char *);
/* hash : calculate hash value from string s */
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
/* lookup : find s in hash table */
struct nlist  *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;      /* s founded */
    return NULL;            /* s not founded */
}
/* install : put (name, defn) in the hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {  /* not founded */
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else                              /* already exsits */
        free((void *) np->defn);        /* free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}
/* undef: remove a name and definition form the table */
void undef(char *s) {
    int h;
    struct nlist *prev, *np;
    prev = NULL;
    h = hash(s);        /* hash value of string s */
    for ( np = hashtab[h]; np != NULL; np = np->next ) {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;      /* remember previous entry */
    }
    if ( np != NULL ) {
        if (prev == NULL)
            hashtab[h] = np->next;
        else
            prev->next = np->next;
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
    }
}

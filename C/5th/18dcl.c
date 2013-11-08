/**
 * 修改dcl程序,使它能够处理输入中的错误
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void errmsg(char *);
int gettoken(void);

extern int  tokentype;      /* type of last token */
extern char token[];        /* last token string */
extern char name[];         /* identifier name */

/* dcl: parse a declarator      */
void dcl(void) {
    int ns;
    for (ns = 0; gettoken() == '*'; )   /* count *'s */
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out." pointer to ");
}

/* dirdcl: parse a direct declaration */
void dirdcl(void) {
    int type;
    if (tokentype == '(') {             /* (dcl)    */
        dcl();
        if (tokentype != ')')
            errmsg("error: missing )\n");
    } else if (tokentype == NAME)       /* variable name */
        strcpy(name,token);
    else
        errmsg("error: expeted name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning ");
        else {
            strcat(out, " array " );
            strcat(out, token);
            strcat(out, " of");
        }
}

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg) {
    printf("%s", msg);
    pretoken = YES;
}

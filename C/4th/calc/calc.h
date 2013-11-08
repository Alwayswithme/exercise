#define NUMBER '0'
#define MAXOP 100   /* max size of operand or operator */
#define NAME 'n'    /* signal that a name was found */
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void clear(void);
void mathfnc(char []);

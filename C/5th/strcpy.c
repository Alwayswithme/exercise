/* strcpy: use array index */
void strcpy (char *s, char *t) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* strcpy: use pointer */
void strcpy(char *s, char *t) {
    while((*s = *t) != '\0') {
        s++;
        i++;
    }
}

void strcpy(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}

void strcpy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}

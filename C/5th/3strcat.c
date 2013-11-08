/* 用指针方式实现第二章中的函数strcat,函数strcat(s,t)将指向的
 * 字符串复制到s指向的字符串的尾部.
 */

/* strcat: concatenatc t to the end of s; pointer version */
void strcat(char *s, char *t) {
    while (*s++)
        ;
    while (*s++ = *t++)
        ;
}

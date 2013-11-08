/**
 * 编写函数strrindex(s, t), 它返回字符串t在s中最右边出现的位置
 * 如果s中不包含t, 则返回-1
 */

#include <string.h>
int strrindex(char s[],char t[]) {
    int i, j, k;
    for ( i = strlen(s) - strlen(t); i >= 0; i-- ) {
        for ( j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

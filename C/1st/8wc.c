/**
 * 编写一个统计空格、 制表符、 换行符个数的程序
 */
#include <stdio.h>

main() {
    int c,ns,nt,nl;

    ns = nt = nl = 0;
    while (( c = getchar() ) != EOF) {
        switch (c) {
            case '\n': /* count newlines */
                nl++; break;
            case '\t': /* count tabs     */
                nt++; break;
            case ' ':  /* count blanks   */
                ns++; break;
            default:
                break;
        }
    }
    printf("there is %d space%s, %d tab%s, %d line%s\n", ns, ns == 1? "" : "s",
            nt, nt == 1? "" : "s", nl, nl == 1? "":"s");
}

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
    printf("there is %d space%s, %d tab%s, %d line%s", ns, ns == 1? "" : "s",
            nt, nt == 1? "" : "s", nl, nl == 1? "":"s");
}

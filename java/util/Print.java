package util;

public class Print {
    public static void main(String[] args) {
        int n = 26;
        int offset = 0;     // 偏移量,和中间的空格还有字母有关系
        int abs = 0;        // 前置空白数
        for (int i = n-1; i != -n; i--) {
            abs = Math.abs(i);
            offset = n-1-abs;
            char c =(char)('a'+offset);
            for (int j=abs; j > 0; j--)
                System.out.print(' ');
            System.out.print(c);
            if (abs == n-1) {
                System.out.println();
                continue;
            }
            else {
                for (int j=0; j < (offset<<1) -1; j++)
                    System.out.print(' ');
                System.out.print(c);
                System.out.println();
            }
        }
    }
}

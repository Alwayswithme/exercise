package util;

import java.util.Scanner;
import java.util.TreeSet;
/**
 * Given two value, gcd and lcm
 * @author phx
 *
 */
public class GcdAndLcm {
    private static Scanner in;
    public static void main(String[] args) {
        int gcd, lcm;
        in = new Scanner(System.in);
        System.out.println("=> Please input a gcd");
        gcd = in.nextInt();
        System.out.println("=> Please input a lcm");
        lcm = in.nextInt();

        int multiResult = gcd * lcm;
        for (Integer temp : findCombination(gcd, lcm)) {
            System.out.printf("x is %d y is %d\n", temp, multiResult / temp);
        }
    }

    /*
     * find the value set through gcd and lcm and return Treeset
     */
    private static TreeSet<Integer> findCombination(int gcd, int lcm) {
        TreeSet<Integer> ts = new TreeSet<>();
        int result = gcd * lcm;
        // 组合对称,只需要遍历一半
        for (int x = gcd; x <= (lcm >> 1); x++) {
            // 第二个循环条件多点约束,提前跳出循环,减少不必要的判断
            for (int y = gcd; y <= lcm && x * y <= result; y++) {
                if (x * y == result && gcd(x, y) == gcd) {
                    // 符合(唯一分解并且最大公约数和输入相等) 条件的x, y放入TreeSet
                    ts.add(x);
                    ts.add(y);
                }
            }
        }
        return ts;
    }

    /*
     * calculate greatest common divisor
     */
    public static long gcd(long m, long n) {
        return (n == 0 ? m : gcd(n, m % n));
    }
}

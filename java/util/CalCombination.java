package util;

import java.util.Scanner;

public class CalCombination {
  private static Scanner in;
  public static void main(String[] args) {
    int gcd, lcm;
    in = new Scanner(System.in);
    System.out.println("=> Please input a gcd");
    gcd = in.nextInt();
    System.out.println("=> Please input a lcm");
    lcm = in.nextInt();
    combination(gcd, lcm);
  }
  /**
   * 根据gcd和lcm计算组合的函数
   */
  static void combination(int gcd, int lcm) {
    int mulResult = gcd * lcm;
    for (int x = gcd; x <= lcm; x++)
      //第二个循环条件多点约束,提前跳出循环,减少不必要的判断
      for (int y = gcd; y != lcm && x*y > mulResult; y++)
        //符合(唯一分解并且最大公约数和输入相等) 条件的x,y输出
        if (x * y == mulResult && gcd(x,y) == gcd)
          System.out.printf("x is %4d,  y is %4d\n", x, y);
  }
  public static long gcd(long m, long n) {
    while(n != 0) {
      long rem = m % n;
      m = n;
      n = rem;
    }
    return m;
  }
}

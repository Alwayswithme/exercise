package other;

import java.util.Scanner;

public class CalGcdAndLcm {

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
	static void combination(int gcd, int lcm) {
		int max = gcd * lcm;
		for (int x = gcd; x <= lcm; x++)
			for (int y = gcd; y <= lcm; y++)
				if (x * y > max) 
					break;
				else if (x * y == max && gcd(x, y) == gcd)
					System.out.printf("x is %4d ,   y is %4d\n", x, y);
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

package util;


public class A {
	public static void main(String[] args) {
		int gcd = 2;
		int lcm = 12;
		int x, y;
		for (x = 0; x < gcd*lcm; x++) {
			for (y = 0; y < gcd*lcm; y++){
				if (x*y == gcd* lcm)
					if (gcd(x,y)==gcd)
					System.out.printf("x is %d y is %d\n", x, y);
				
			}
		}
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

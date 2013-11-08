package util;

import java.math.BigInteger;

public class Power {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long x = 2;
		int n = 222;
		pow(x, n);
//		BigInteger a = new BigInteger("2");
//		System.out.println(a.pow(2222222));
	}

	public static long pow(long x, int n) {
		// TODO Auto-generated method stub
		if ( n == 0) {
			return 1;
		}
		if (isEven(n))
			return pow(x*x, n/2);
		else
			return pow(x*x, n/2) * x;
	}

	public static boolean isEven(int n) {
		if ((n&1) == 1)
			return true;
		else
			return false;
	}

}

package other;

public class GreatestCommonDivisor {

	public static void main(String[] args) {
		System.out.println(lcm(48,42));
	}
	public static long gcd(long m, long n) {
		while(n != 0) {
			long rem = m % n;
			m = n;
			n = rem;
		}
		return m;
	}
	public static long lcm(long m, long n) {
		long result = (m * n);
		result /= gcd(m,n);
		return result;
	}
}

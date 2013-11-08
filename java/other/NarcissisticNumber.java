package other;

import java.math.BigInteger;

public class NarcissisticNumber {
	
	public final static int N = 21;
	/**
	 * 數組預先存放0 ~ 9的N次方 
	 */
	public static BigInteger[] numAfterPow = new BigInteger[10];
	private BigInteger MAXNUM = BigInteger.TEN.pow(N).subtract(BigInteger.ONE);
	private BigInteger MINNUM = BigInteger.TEN.pow(N - 1);
	public NarcissisticNumber() {
		for (int i = 0; i < 10; i++) {
			numAfterPow[i] = new BigInteger(String.valueOf(i),10);
		}
		for (int i = 2; i < 10; i++) {
			numAfterPow[i] = numAfterPow[i].pow(N);
		}
	}
	public void find() {
		for (BigInteger i = MAXNUM; i.compareTo(MINNUM) > 0; i.subtract(BigInteger.ONE)) {
			
		}
	}
	public static void main(String[] args) {

	}

}

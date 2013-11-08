package other;


public class Variance {
	/**
	 * formula D(X) = E(X^2)-[E(X)]^2;
	 * @param args
	 */
	public static void main(String[] args) {
		int[] arr = {1, 2, 3, 4};
	
		
		double sum1 = 0, sum2 = 0;
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			sum1 += arr[i] *arr[i];
			sum2 += arr[i];
	
		}

		double result = sum1/n - (sum2/n)*(sum2/n);
		System.out.println(result);
	}

}

package search;

import java.util.Arrays;
import java.util.List;

public class MaxSubsequence {

	public static void main(String[] args) {
		Integer[] a = {1, -2, 3, 0, 5, 10, -4, 7, 4, 6, -5};
		maxSubMultiply(a);
	}
	/**
	 * Linear-time maximum contiguous subsequence sum algorithm
	 */
	static void maxSubMultiply(Integer[] arr) {
		int maxSum, thisSum, start, end, current;
		maxSum = start = end = current = 0;
		thisSum = 1;
		for (int i = 0, len = arr.length; i < len; i++) {
			thisSum *= arr[i];
			if (thisSum > maxSum) {
				maxSum = thisSum;
				start = current;
				end = i;
			} else if (thisSum <= 0) {
				thisSum = 1;
				current = i + 1;
			}
		}
		List<Integer> a = Arrays.asList(arr).subList(start, end+1);
		System.out.println("Max subsequence is: "+ a +
				"\nStart index: "+ start + "\nEnd index: " + end);
	}
	/**
	 * Linear-time maximum contiguous subsequence sum algorithm
	 */
	public static int maxSubSum(Integer[] a) {
		int maxSum = 0, thisSum = 0;
		for( int j = 0; j < a.length; j++) {
			thisSum += a[j];
			if (thisSum > maxSum)
				maxSum = thisSum;
			else if(thisSum < 0)
				thisSum = 0;
		}
		return maxSum;
	}
}

package search;

import java.util.Arrays;
import java.util.TreeSet;

public class BinarySearch {

	private static final int NOT_FOUND = -1;
	public static void main(String[] args) {
		Integer[]  a = {3,4,1,4,12,5,6,9,11,53,13,55,36,90,38,95,74};
		TreeSet<Integer> ts = new TreeSet<Integer>(Arrays.asList(a)); //sort
		a = ts.toArray(new Integer[ts.size()]);			//change to array
		System.out.println(Arrays.toString(a));
		int idx = binarySearch(a, 7);
		System.out.print(idx);
	}
	/**
	 * Performs the standard binary search
	 * @return index where item is found, or -1 if not found.
	 */
	public static <T extends Comparable<? super T>> int binarySearch(T[] array, T key) {
		int low = 0, high = array.length - 1;
		
		while (low <= high) {
			int mid = low + high >> 1;
			
			if (array[mid].compareTo(key) < 0)
				low = mid + 1;
			else if (array[mid].compareTo(key) > 0)
				high = mid - 1;
			else
				return mid;
		}
		return NOT_FOUND;
	}
}

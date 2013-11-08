package sort;

import java.util.Arrays;

import util.Power;

public class Reorder {

	public static void main(String[] args) {
		Integer[] list = { 1, 2, 3, 4, 5, 7, 9, 11 };
		reorderOddEven(list);
	}

	public static void reorderOddEven(Integer[] list) {
		int length = list.length;
	
		int begin = 0;
		int end = length - 1;
		while (begin < end) {
			while (begin < end && Power.isEven(list[begin]))
				begin++;
			while (begin < end && !Power.isEven((list[end])))
				end--;
			if (begin < end) {
				int temp = list[begin];
				list[begin] = list[end];
				list[end] = temp;
			}
		}

		Arrays.sort(list, 0, begin);
		Arrays.sort(list, end, list.length);
		for (int i = 0; i < length; i++) {
			System.out.print(list[i] + " ");
		}
	}

}

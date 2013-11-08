package bitwise;

public class FindTwoUniq {

	public static void main(String[] args) {
		int[] arr = {1, 2, 3, 4, 5, 6, 7, 7, 5, 4, 3, 2};
		find(arr);
	}
	public static void find(int[] arr) {
		int xorResult = 0, count;
		int len = arr.length;
		for (int i = 0; i < len; i++)
			xorResult ^= arr[i];
		for (count = 0; count < len; count++ ) 
			if (((xorResult>>1)&1) == 1)
				break;
		int uniq1 = 0, uniq2 = 0;
		for (int i = 0; i < len; i++) {
			if ((arr[i]>>count & 1) == 1) {
				uniq1 ^= arr[i];
			}else
				uniq2 ^= arr[i];
		}
		System.out.printf("The two unique number is %d and %d", uniq1, uniq2);
				
		
	}
}

package util;

import other.CalGcdAndLcm;

public class LeftShift {
	public static void main(String[] args) {
		char[] chars = "abcvhvjhd".toCharArray();
		int m = 5;
		rotate2(chars, m);
		System.out.println(chars);
	}

	private static void rotate2(char[] chars, int m) {
		int lenOfStr = chars.length;
		int numOfGroup = (int) CalGcdAndLcm.gcd(lenOfStr, m);
		int i, j;
		
		for (i = 0; i < numOfGroup; i++) {
			char tmp = chars[i];
			int last = i;
			for (j = (i + m)%lenOfStr; j != i; j = (j+m)%lenOfStr) {
				chars[last] = chars[j];
				last = j;
			}
			chars[last] = tmp;
		}
	}

	static void rotate(char[] chars, int m) {
		int lenOfStr = chars.length;
		int numOfGroup = (int) CalGcdAndLcm.gcd(lenOfStr, m);
		int elemInSub = lenOfStr / numOfGroup;
		
		for(int j = 0; j < numOfGroup; j++) {
			char tmp = chars[j];
			int i;
			for (i = 0; i < elemInSub - 1; i++)
				chars[(j + i * m)%lenOfStr] = chars[(j+(i+1)*m) % lenOfStr];
			chars[(j + i * m) % lenOfStr] = tmp;
		}
	}
}

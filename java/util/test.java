package util;

import java.util.Arrays;

public class test {

	public static void main(String[] args) {
		int MAX = 100;
		int is_p[] = new int[MAX + 1];
		int total = 0;
		int p[] = new int[MAX];
		for(int i = 0; i < is_p.length; i++) {
			is_p[i] = 1;
		}
		for (int i = 2; i <= MAX; i++) {
			if (is_p[i] != 0)
				p[total++] = i;
			for (int j = 0; j < total && i * p[j] <= MAX; j++) {
				is_p[i*p[j]] = 0;
				if ((i % p[j]) == 0)
					break;
			}
		}
		System.out.println(Arrays.toString(is_p));
		System.out.println(Arrays.toString(p));
	}

}

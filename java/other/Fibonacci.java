package other;

public class Fibonacci {

	public static void main(String[] args) {
		for (int i = 0; i < 10 ; i++) {
			System.out.print(fib(i)+"   ");
		}
	}
	public static int fib(int num) {
		int a = 0, b = 1;
		for (int i = 0; i <= num; i++){
			int temp = a;
			a = b;
			b = temp+b;
		}
		return a;
	}
}

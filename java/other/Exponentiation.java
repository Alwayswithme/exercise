package other;

public class Exponentiation {

    public static void main(String[] args) {
        long result = pow(2, 4);
        System.out.println(result);
    }

    public static long pow(long x, int n) {
        if (n == 0)
            return 1;
        else if (isEven(n))
            return pow(x * x, n / 2);
        else
            return pow(x * x, n / 2) * x;
    }

    private static boolean isEven(int n) {
        return (n & 1) != 1;
    }
}

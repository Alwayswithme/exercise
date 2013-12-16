package util;

import java.util.ArrayList;
import java.util.List;

public class Factorization {
    public static void main(String[] args) {
        System.out.println("Primefactors of 44");
        System.out.println(primeFactors(44));
        System.out.println("Primefactors of 3");
        System.out.println(primeFactors(3));
        System.out.println("Primefactors of 32");
        System.out.println(primeFactors(32));
    }

    static boolean isPrime(int num) {
        return !new String(new char[num]).matches(".?|(..+?)\\1+");
    }

    static List<Integer> primeFactors(int n) {
        List<Integer> factors = new ArrayList<>();
        for (int i = 2; i <= n / i; i++) {
            while (n % i == 0) {
                factors.add(i);
                n /= i;
            }
        }
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }
}

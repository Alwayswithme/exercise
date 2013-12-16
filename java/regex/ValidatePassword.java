package regex;

import java.util.Scanner;

import org.junit.Test;

public class ValidatePassword {
    private static Scanner in;
    private static final String FORMATTER = ".*%s.*";
    private static final String OUTPUT = "Password is %svalid";
    public static void main(String[] args) {
        in = new Scanner(System.in);
        String input = in.nextLine();
        System.out.println(
                String.format(OUTPUT, checkPassword(input) ? "" : "not"));
    }

    static boolean checkPassword(String input) {
        int strlen = input.length();
        return (strlen >= 8 && strlen <= 16 && count(input) >= 3);
    }

    static int count(String input) {
        int count = 0;
        String[] regexs = "[a-z] [A-Z] [0-9] [~!@#$%^]".split(" ");
        for (String regex : regexs) {
            // 根据正则数组遍历,符合则计数加一
            count = input.matches(String.format(FORMATTER, regex)) ? 
                    count + 1 : count;
        }
        return count;
    }

    @Test
    public void test() {
        String[] input = new String[6];
        input[0] = "absA1~"; // less than 8
        input[1] = "ASDQWEasdqwe123~!@$%^"; // great than 16
        input[2] = "asAS12!@"; // contains four different char
        input[3] = "asdASd1223"; // contains three different char
        input[4] = "asdasaa1223"; // contains two different char
        input[5] = "helloworld"; // contains one char
        for (String i : input) {
            System.out.println(
                    String.format(OUTPUT, checkPassword(i) ? "" : "not "));
        }
    }
}

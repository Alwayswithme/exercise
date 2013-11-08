package regex;

import java.util.Scanner;

import org.junit.Test;

public class ValidatePassword {
  private static Scanner in;
  private static final String FORMATTER = ".*%s.*";
  public static void main(String[] args) {
	  in = new Scanner(System.in);
	  String input = in.nextLine();
	  checkPassword(input);
  }
  static void checkPassword(String input) {
    int length = input.length();
    if (length >= 8 && length <= 16 && count(input) >= 3)
      System.out.println("=> Password is valid");
    else
      System.out.println("=> Password is not valid");
  }
  private static int count(String input) {
    int count = 0;
    String[] regexs = 
      "[a-z] [A-Z] [0-9] [~!@#$%^]".split(" ");
    for(String regex: regexs)     //根据给定的正则数组遍历,符合则计数加一
      count = input.matches(String.format(FORMATTER, regex)) ? count+1 : count;
    return count;
  }
  
	/*
	 * Test case make sure the output will be 
	 * => Password is not valid 
	 * => Password is not valid 
	 * => Password is valid 
	 * => Password is valid 
	 * => Password is not valid 
	 * => Password is not valid
	 */
  @Test
  public void test() {
	  String[] input = new String[6];
	  input[0] = "absA1~";      // less than 8
	  input[1] = "ASDQWEasdqwe123~!@$%^"; // great than 16
	  input[2] = "asAS12!@";		// contains four different char
	  input[3] = "asdASd1223";		// contains three different char
	  input[4] = "asdasaa1223";		// contains two different char
	  input[5] = "helloworld";		// contains one char
	  for (String i: input) {
		  checkPassword(i);
	  }
  }
}


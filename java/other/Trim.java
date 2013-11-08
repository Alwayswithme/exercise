package other;
import static java.lang.System.out;
public class Trim {

	public static void main(String[] args) {
	    String temp = "    Jekyll     is    the     best     static "
	    		+ " site generator   ever!    ";

		out.println(temp.replaceAll("^ *", "").replaceAll(" +", " ").replaceAll(" $",""));
		
	}

}

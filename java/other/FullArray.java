package other;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class FullArray {
	private static HashSet<String> fullArray = new HashSet<String>();
	public static final int N = 4;		// number of element 
	public static void main(String[] args) {
		LinkedList<Integer> l = new LinkedList<Integer>();
		for (int i = 1; i <= N; i++) {
			l.add(i);
		}

		findArray(l,"");
		System.out.println(N+"! = " + fullArray.size());
		
		for (Iterator<String> i = fullArray.iterator(); i.hasNext(); )
			System.out.println(i.next());
		
	}
	public static <T> void findArray(List<T> list, String s) {
		if (list.size() == 0) {
			fullArray.add(s);
			return;
		}
		for (int i = 0; i < list.size(); i++) {
			List<T> temp = new LinkedList<T>(list);
			findArray(temp, s+temp.remove(i));
		}
	}
}

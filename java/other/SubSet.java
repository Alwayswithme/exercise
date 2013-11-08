package other;


import java.util.ArrayList;
import java.util.TreeSet;


public class SubSet {
	public static void main(String[] args) {
		TreeSet<String> mainSet = new TreeSet<String>(); //main set use to get subset
		for(int i = 0; i < 5; i++) {
			char c = (char) ('a' + i);
			
			mainSet.add(c+"");			//add element
		}
		ArrayList<TreeSet<String>> allSubset = getSubset(mainSet);
		for (TreeSet<String> treeSet : allSubset) 
			System.out.println(treeSet.toString());
	}

	private static ArrayList<TreeSet<String>> getSubset(TreeSet<String> mainSet) {
		int elementNum = mainSet.size();        // this also means how many bits in the binset
		ArrayList<TreeSet<String>> allsubset = new ArrayList<TreeSet<String>>();
		
		String[] elements = mainSet.toArray(new String[elementNum]);   //single element
		
		String[] bitSet = getBinary(elementNum);   //use binary code to get sub subset number
		int subsetNum = bitSet.length;            
         
		for (int i=0; i < subsetNum; i++) {
			String value = bitSet[i];
			TreeSet<String> subset = new TreeSet<String>();
			for (int j=0; j < value.length(); j++) {
				if (value.charAt(j) == '1')
					subset.add(elements[j]);
			}
			allsubset.add(subset);
		}
		
		return allsubset;
	}

	private static String[] getBinary(int size) {		
		int subsetNum = 1<<size;
		String[] result = new String[subsetNum];
		//get the number's which is less 2^size in binary base
		for (int i = 0; i < subsetNum; i++) {
			result[i] = Integer.toBinaryString(i);
		}
		return result;
	}

}
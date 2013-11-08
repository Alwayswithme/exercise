package other;

public class Kmp {

	public static void main(String[] args) {
		String a = "asdflasdfasdfasdfagerheq	weqwekhasdfghjkleddddddddddjgjhkgjkghhgkdyrsoijioqweiuotasds";
		String b = "jgjhkg";
		System.out.println("\n"+indexKMP(a, b)+"  "+a.indexOf(b));
	}
	public static int indexKMP(String s1, String s2) {
		return indexKMP(s1, s2, 0);
	}
/**
 * 返回字符串t在字符串s中第pos個字符後的位置,若不存在,則返回-1
 * @param s
 *       查找主字符串
 * @param t
 *       需要匹配的字符串
 * @param pos
 *       從第幾位開始查找
 */
	public static int indexKMP(String s, String t, int pos) {
		int i = pos, j = 0; // 主字符串s和匹配字符串t的索引
		int[] next = new int[t.length()];// 記錄t字符串重復性的數組
		
		next(t, next);
		while(i < s.length() && j < t.length()) {
			if (j == -1 || s.charAt(i) == t.charAt(j)) { /* 兩字符相等.則比較下一處 */
				i++;j++;
			}else
				j = next[j];		//j退回到合適位置
		}
		if (j == t.length())
			return i-t.length();
		else
			return -1;
	}
	/**
	 * 計算t字符串的重復性next數組
	 * @param t
	 * @param next
	 */
	private static void next(String t, int[] next) {
		int i = 0, j = -1; // i 記錄當前字符索引; j 表示前綴字符回溯時用到的值
		
		next[0] = -1;
		while (i < t.length() - 1) {
			if ( j == -1 || t.charAt(i) == t.charAt(j)) {
				i++; j++;
				if (t.charAt(i) != t.charAt(j)) 
					next[i] = j;		// 如果當前字符與前綴字符不同
				else	 				// 則當前的j爲next在i位置的值
					next[i] = next[j];  // 否則將前綴字符的next值賦值給當前位置
			} else
				j = next[j];            // 字符不同,j回溯
		}
	}
}

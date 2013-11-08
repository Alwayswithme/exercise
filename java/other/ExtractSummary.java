package other;

import java.util.Arrays;  
import java.util.HashMap;  
import java.util.HashSet;  
  
public class ExtractSummary {  
  
    private static String word;

	/** 
     * @param args 
     */  
    public static void main(String[] args) {  
        System.out.println(extractSummary("a b c d a b c x a b x d c a b x d", new String[] { "a", "c", "b", "d", "x" }));  
    }  
  
    public static String extractSummary(String description, String[] keywords) {  
  
        String[] words = description.split(" ");  
  
        HashSet<String> keywordSet = new HashSet<String>(Arrays.asList(keywords));  
        HashMap<String, Integer> keywordMap = new HashMap<String, Integer>();  
  
        int savedStart = 0;  
        int savedEnd = 0;  
        int start = 0;  
        int end = 0;  
  
        while (end < words.length) {  
            // expand end  
            for (; end < words.length; end++) {  
                word = words[end];  
                if (keywordSet.contains(word)) {  
                    if (keywordMap.containsKey(word)) {  
                        keywordMap.put(word, keywordMap.get(word) + 1);  
                    } else {  
                        keywordMap.put(word, 1);  
                        if (keywordMap.size() == keywordSet.size()) {  
                            // we have a substring, break  
                            end++;  
                            break;  
                        }  
                    }  
                }  
            }  
  
            if (keywordMap.size() < keywordSet.size()) {  
                // we found no more substring  
                break;  
            }  
  
            // shrink start  
            for (; start < end; start++) {  
                word = words[start];  
                if (keywordSet.contains(word)) {  
                    Integer value = keywordMap.remove(word);  
                    if (value != 1) {  
                        keywordMap.put(word, value - 1);  
                    } else if (keywordMap.size() < keywordSet.size()) {  
						// we have another minimum substring, save start and end
						// then break
						if (savedEnd == 0
								|| (savedEnd - savedStart) > (end - start)) {
							savedStart = start;
							savedEnd = end;
						}
						start++;
						break;
					}
				}
			}
        }  
  
        if (savedEnd != 0) {  
            // we have found a minimum substring  
            StringBuilder sb = new StringBuilder(words[savedStart]);  
            for (int i = savedStart + 1; i < savedEnd; i++) {  
                sb.append(" ").append(words[i]);  
            }  
            return sb.toString();  
        } else {  
            return "";  
        }  
    }  
}  
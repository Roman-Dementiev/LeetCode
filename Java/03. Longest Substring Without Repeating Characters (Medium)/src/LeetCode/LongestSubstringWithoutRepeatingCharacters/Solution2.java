/**
 * 
 */
package LeetCode.LongestSubstringWithoutRepeatingCharacters;

import java.util.HashMap;

/**
 * @author Roman Dementiev
 *
 */
public class Solution2
{
	int lengthOfLongestSubstring(String str)
	{
		return lengthOfLongestSubstring_Ascii(str);
	}

	int lengthOfLongestSubstring_Ascii(String str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

		int /*maxStart = 0,*/ curStart = 0;
		int maxLength = 1, curLength = 1;
		int[] curChars = new int[127];
		curChars[str.charAt(0)] = 1;

		for (int next = 1; next < length; next++) {
			char ch = str.charAt(next);
			if (curChars[ch] > 0) {
				if (curLength > maxLength) {
			//		maxStart = curStart;
					maxLength = curLength;
				}
				int newStart = curChars[ch];
				for (int k = curStart; k < newStart; k++) {
					curChars[str.charAt(k)] = 0;
				}
				curStart = newStart;
				curLength = next - curStart;
			}
			curChars[ch] = next + 1;
			curLength++;
		}
		if (curLength > maxLength) {
		//	maxStart = curStart;
			maxLength = curLength;
		}

		return maxLength;
	}

	int lengthOfLongestSubstring_Any(String str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

		int /*maxStart = 0,*/ curStart = 0;
		int maxLength = 1, curLength = 1;
		HashMap<Character, Integer> curChars = new HashMap<Character, Integer>();
		curChars.put(str.charAt(0), 0);

		for (int next = 1; next < length; next++) {
			char ch = str.charAt(next);
			if (curChars.containsKey(ch)) {
				if (curLength > maxLength) {
			//		maxStart = curStart;
					maxLength = curLength;
				}
				int newStart = curChars.get(ch) + 1;
				for (int k = curStart; k < newStart; k++) {
					curChars.remove(str.charAt(k));
				}
				curStart = newStart;
				curLength = next - curStart;
			}
			curChars.put(ch, next);
			curLength++;
		}
		if (curLength > maxLength) {
		//	maxStart = curStart;
			maxLength = curLength;
		}

		return maxLength;
	}

}

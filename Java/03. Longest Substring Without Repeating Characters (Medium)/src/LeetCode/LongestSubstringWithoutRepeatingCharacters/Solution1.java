/**
 * 
 */
package LeetCode.LongestSubstringWithoutRepeatingCharacters;

import java.util.HashSet;

/**
 * @author Roman
 *
 */
public class Solution1
{
	public int lengthOfLongestSubstring(String str)
	{
		return lengthOfLongestSubstring_Ascii(str);
	}

	int lengthOfLongestSubstring_Ascii(String str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

//		int maxStart = 0;
		int maxLength = 1;
		for (int start = length-2; start >= 0; start--) {
			boolean[] chars = new boolean[127];
			chars[str.charAt(start)] = true;
			int end;
			for (end = start+1; end < length; end++) {
				char ch = str.charAt(end);
				if (chars[ch])
					break;
				chars[ch] = true;
			}
			int len = end - start;
			if (len > maxLength) {
			//	maxStart = start;
				maxLength = len;
			}
		}
		return maxLength;
	}

	int lengthOfLongestSubstring_AnyChars(String str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

//		int maxStart = 0;
		int maxLength = 1;
		for (int start = 0; start < length-1; start++) {
			HashSet<Character> chars = new HashSet<Character>();
			chars.add(str.charAt(start));
			int end;
			for (end = start+1; end < length; end++) {
				char ch = str.charAt(end);
				if (chars.contains(ch))
					break;
				chars.add(ch);
			}
			int len = end - start;
			if (len > maxLength) {
			//	maxStart = start;
				maxLength = len;
			}
		}
		return maxLength;
	}
}

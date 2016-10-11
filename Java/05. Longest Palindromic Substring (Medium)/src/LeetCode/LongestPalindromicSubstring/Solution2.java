/**
 * 
 */
package LeetCode.LongestPalindromicSubstring;

/**
 * @author Roman Dementiev
 *
 */
public class Solution2
{
	class Longest {
		public int start = 0;
		public int length = 1;
	}
	
	String longestPalindrome(String str)
	{
		int length = str.length();
		if (length == 0)
			return str;

		Longest longest = new Longest();
		for (int i = 1; i < length; i++) {
			expandPalindrome(str, i, i, longest);
			if (str.charAt(i) == str.charAt(i-1)) {
				expandPalindrome(str, i-1, i, longest);
			}
		}

		return str.substring(longest.start, longest.start+longest.length);
	}
	
	void expandPalindrome(String str, int l, int r, Longest longest)
	{
		assert(l >= 0 && l <= r && r < str.length() && str.charAt(l) == str.charAt(r));

		do {
			l--;
			r++;
		} while (l >= 0 && r < str.length() && str.charAt(l) == str.charAt(r));

		int len = r - l - 1;
		if (longest.length < len) {
			longest.length = len;
			longest.start = l + 1;
		}
	}
}

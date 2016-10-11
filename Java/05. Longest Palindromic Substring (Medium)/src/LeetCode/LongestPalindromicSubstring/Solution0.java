/**
 * 
 */
package LeetCode.LongestPalindromicSubstring;

/**
 * @author Roman
 *
 */
public class Solution0
{
    public String longestPalindrome(String str)
    {
		int n = str.length();
		if (n == 0)
			return str;


		int longestStart = 0;
		int longestLength = 1;

		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= i + longestLength; j--) {
				if (isPalindrome(str, i, j)) {
					longestStart = i;
					longestLength = j - i + 1;
					continue;
				}
			}
		}

		return str.substring(longestStart, longestStart+longestLength);
    }

	static boolean isPalindrome(String str, int first, int last)
	{
		do {
			if (str.charAt(first++) != str.charAt(last--))
				return false;
		}
		while (first < last);

		return true;
	}
}

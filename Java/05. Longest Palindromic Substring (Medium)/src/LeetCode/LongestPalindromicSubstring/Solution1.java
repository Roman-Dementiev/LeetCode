/**
 * 
 */
package LeetCode.LongestPalindromicSubstring;

/**
 * @author Roman Dementiev
 *
 */
public class Solution1
{
	public String longestPalindrome(String str)
	{
		int n = str.length();
		if (n == 0)
			return str;


		int longestStart = 0;
		int longestLength = 1;

		boolean[][] dp = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
			if (i > 0 && str.charAt(i) == str.charAt(i-1)) {
				dp[i-1][i] = true;
				longestStart = i-1;
				longestLength = 2;
			}
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0, j = len-1; j < n; i++, j++) {
				if (dp[i+1][j-1] && str.charAt(i)==str.charAt(j)) {
					dp[i][j] = true;
					if (len > longestLength) {
						longestStart = i;
						longestLength = len;
					}
				}
			}
		}

		return str.substring(longestStart, longestStart+longestLength);
	}
}

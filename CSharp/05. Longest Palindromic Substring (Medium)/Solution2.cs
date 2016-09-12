using System;

namespace LeetCode
{
	class Solution2
	{
		int longestStart;
		int longestLength;
		bool[,] dp;

		public string LongestPalindrome(string str)
		{
			if (String.IsNullOrEmpty(str))
				return String.Empty;


			longestStart = 0;
			longestLength = 1;

			int n = str.Length;
			bool[,] dp = new bool[n, n];
			dp[0, 0] = true;
			for (int i = n-2; i >= 0; i--) {
				dp[i, i] = true;
				if (str[i] == str[i+1]) {
					dp[i, i+1]= true;
					longestStart = i;
					longestLength = 2;
				}
			}

			for (int len = 3; len <= n; len++) {
				for (int i = 0, j = len-1; j < n; i++, j++) {
					if (dp[i+1, j-1] && str[i]==str[j]) {
						dp[i, j] = true;
						if (len > longestLength) {
							longestStart = i;
							longestLength = len;
						}
					}
				}
			}

			return str.Substring(longestStart, longestLength);
		}
	}
}

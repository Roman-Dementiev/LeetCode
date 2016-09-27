using System;


namespace LeetCode
{
	class Solution0
	{

		public string LongestPalindrome(string str)
		{
			if (String.IsNullOrEmpty(str))
				return String.Empty;

			int n = str.Length;
			int longestStart = 0;
			int longestLength = 1;

			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= i + longestLength; j--) {
					if (IsPalindrome(str, i, j)) {
						longestStart = i;
						longestLength = j - i + 1;
						continue;
					}
				}
			}

			return str.Substring(longestStart, longestLength);
		}

		static bool IsPalindrome(string str, int first, int last)
		{
			do {
				if (str[first++] != str[last--])
					return false;
			}
			while (first < last);

			return true;
		}
	}
}

using System;
using System.Diagnostics;
using TestSample = LeetCode.TestSample<string, LeetCode.Void, string>;


namespace LeetCode
{
	class LongestPalindromeSubstring : TestProgram
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample("", ""),
				new TestSample("a", "a"),
				new TestSample("ab", "a"),
				new TestSample("aba", "aba"),
				new TestSample("abab", "aba"),
				new TestSample("abba", "abba"),
				new TestSample("aaaa", "aaaa"),
				new TestSample(null)
			};

			var sol = new Solution();
			RunTests(tests, sol.LongestPalindrome);
		}
	}

	public class Solution
	{
		public void ExpandPalindrome(string str, int l, int r, ref int longetsStart, ref int longestLength)
		{
			Debug.Assert(l >= 0 && l <= r && r < str.Length && str[l]==str[r]);

			do {
				l--;
				r++;
			}
			while (l >= 0 && r < str.Length && str[l] == str[r]);

			int len = r - l - 1;
			if (longestLength < len) {
				longestLength = len;
				longetsStart = l + 1;
			}
		}

		public string LongestPalindrome(string str)
		{
			if (String.IsNullOrEmpty(str))
				return String.Empty;

			int longestStart = 0;
			int longestLength = 1;
			for (int i = 1; i < str.Length; i++) {
				ExpandPalindrome(str, i, i, ref longestStart, ref longestLength);
				if (str[i] == str[i-1]) {
					ExpandPalindrome(str, i-1, i, ref longestStart, ref longestLength);
				}
			}

			return str.Substring(longestStart, longestLength);
		}
	}

}

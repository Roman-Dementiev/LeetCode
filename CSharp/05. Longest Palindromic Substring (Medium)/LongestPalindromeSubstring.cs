using System;
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

			var sol = new Solution0();
			RunTests(tests, sol.LongestPalindrome);
		}
	}
}

using System;
using TestSample = LeetCode.TestSample<string, LeetCode.Void, int>;


namespace LeetCode
{
	class LongestSubstringWithoutRepeatingCharacters : TestProgram
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample("abcabcbb", 3),
				new TestSample("bbbbb", 1),
				new TestSample("pwwkew", 3),
				new TestSample("", 0),
				new TestSample(null, 0)
			};

			var sol = new Solution();
			RunTests<string,int>(tests, sol.LengthOfLongestSubstring);
		}
	}

}

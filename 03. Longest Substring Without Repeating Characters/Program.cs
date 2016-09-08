using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Test = LeetCode.Test<string, string, int>;

namespace LeetCode
{
	class Program
	{
		static void Main(string[] args)
		{
			var tests = new Test[] {
				new Test("abcabcbb", 3),
				new Test("bbbbb", 1),
				new Test("pwwkew", 3),
				new Test("", 0),
				new Test(null, 0)
			};

			var sol = new Solution();
			sol.RunTests(tests, sol.LengthOfLongestSubstring);
		}
	}

	public partial class Solution
	{
		public int LengthOfLongestSubstring(string s)
		{
			if (String.IsNullOrEmpty(s))
				return 0;

			int maxStart = 0, curStart = 0;
			int maxLength = 1, curLength = 1;
			var curChars = new Dictionary<char, int>();
			curChars.Add(s[0], 0);

			for (int next = 1; next < s.Length; next++) {
				char ch = s[next];
				if (curChars.ContainsKey(ch)) {
					if (curLength > maxLength) {
						maxStart = curStart;
						maxLength = curLength;
					}
					int newStart = curChars[ch] + 1;
					for (int k = curStart; k < newStart; k++) {
						curChars.Remove(s[k]);
					}
					curStart = newStart;
					curLength = next - curStart;
				}
				curChars.Add(ch, next);
				curLength++;
			}
			if (curLength > maxLength) {
				maxStart = curStart;
				maxLength = curLength;
			}

			return maxLength;
		}
	}

}

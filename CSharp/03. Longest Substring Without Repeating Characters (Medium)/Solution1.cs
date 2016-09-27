using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
	class Solution1
	{
		public int LengthOfLongestSubstring(string str)
		{
			if (String.IsNullOrEmpty(str))
				return 0;

			//		int maxStart = 0;
			int maxLength = 1;
			for (int start = 0; start < str.Length - 1; start++) {
				var chars = new HashSet<char>();
				chars.Add(str[start]);
				int end;
				for (end = start + 1; end < str.Length; end++) {
					char ch = str[end];
					if (chars.Contains(ch))
						break;
					chars.Add(ch);
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
}

using System;

namespace LeetCode
{
	class Solution0
	{
		public int LengthOfLongestSubstring(string str)
		{
			if (String.IsNullOrEmpty(str))
				return 0;

			// int maxStart = 0;
			int maxLength = 1;
			for (int start = str.Length - 2; start >= 0; start--) {
				int end;
				for (end = start + 1; end < str.Length; end++) {
					char ch = str[end];
					bool repeating = false;
					for (int i = start; i < end; i++) {
						if (str[i] == ch) {
							repeating = true;
							break;
						}
					}
					if (repeating)
						break;
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

#pragma once
#include"LeetCode.h"
#include <unordered_set>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution0

class Solution
{
public:
	int lengthOfLongestSubstring(string str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

//		int maxStart = 0;
		int maxLength = 1;
		for (int start = length-2; start >= 0; start--) {
			int end;
			for (end = start+1; end < length; end++) {
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

};

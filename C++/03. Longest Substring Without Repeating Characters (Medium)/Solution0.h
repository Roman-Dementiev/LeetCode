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
	int lengthOfLongestSubstring(string s)
	{
		int length = s.length();
		if (length == 0)
			return 0;

//		int maxStart = 0;
		int maxLength = 1;
		for (int start = 0; start < length-1; start++) {
			unordered_set<char> chars;
			chars.insert(s[start]);
			int end;
			for (end = start+1; end < length; end++) {
				char ch = s[end];
				if (chars.find(ch) == chars.end()) {
					chars.insert(ch);
				} else {
					break;
				}
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

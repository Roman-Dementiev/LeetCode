#pragma once
#include "LeetCode.h"
#include <cassert>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution2

class Solution
{
public:

	string longestPalindrome(string str)
	{
		int length = str.length();
		if (length == 0)
			return str;

		int longestStart = 0;
		int longestLength = 1;
		for (int i = 1; i < length; i++) {
			ExpandPalindrome(str, i, i, longestStart, longestLength);
			if (str[i] == str[i - 1]) {
				ExpandPalindrome(str, i - 1, i, longestStart, longestLength);
			}
		}

		return str.substr(longestStart, longestLength);
	}
	void ExpandPalindrome(string str, int l, int r, int& longetsStart, int& longestLength)
	{
		assert(l >= 0 && l <= r && r < str.length() && str[l] == str[r]);

		do {
			l--;
			r++;
		} while (l >= 0 && r < str.length() && str[l] == str[r]);

		int len = r - l - 1;
		if (longestLength < len) {
			longestLength = len;
			longetsStart = l + 1;
		}
	}
};

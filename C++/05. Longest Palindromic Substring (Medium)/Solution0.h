#pragma once
#include "LeetCode.h"

#ifdef Solution
#undef Solution
#endif
#define Solution Solution0


class Solution
{
public:
	string longestPalindrome(string str)
	{
		int n = str.length();
		if (n == 0)
			return str;


		int longestStart = 0;
		int longestLength = 1;

		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= i + longestLength; j--) {
				if (IsPalindrome(str, i, j)) {
					longestStart = i;
					longestLength = j - i + 1;
					continue;
				}
			}
		}

		return str.substr(longestStart, longestLength);
	}

	static bool IsPalindrome(string& str, int first, int last)
	{
		do {
			if (str[first++] != str[last--])
				return false;
		}
		while (first < last);

		return true;
	}
};

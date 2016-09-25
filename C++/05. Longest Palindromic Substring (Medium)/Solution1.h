#pragma once
#include "LeetCode.h"

#ifdef Solution
#undef Solution
#endif
#define Solution Solution1

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

		bool** dp = new bool*[n];
		for (int i = 0; i < n; i++) {
			dp[i] = new bool[n];
			memset(dp[i], 0, n*sizeof(bool));
			dp[i][i] = true;
			if (i > 0 && str[i] == str[i-1]) {
				dp[i-1][i] = true;
				longestStart = i-1;
				longestLength = 2;
			}
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0, j = len-1; j < n; i++, j++) {
				if (dp[i+1][j-1] && str[i]==str[j]) {
					dp[i][j] = true;
					if (len > longestLength) {
						longestStart = i;
						longestLength = len;
					}
				}
			}
		}

		return str.substr(longestStart, longestLength);
	}
};

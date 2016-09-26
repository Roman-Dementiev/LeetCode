#pragma once
#include "LeetCode.h"
#include <unordered_map>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution1


class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		if (s.length() == 0)
			return 0;

		int /*maxStart = 0,*/ curStart = 0;
		int maxLength = 1, curLength = 1;
		unordered_map<char, int> curChars;
		curChars.insert(make_pair(s[0], 0));

		for (int next = 1; next < s.length(); next++) {
			char ch = s[next];
			if (curChars.find(ch) !=  curChars.end()) {
				if (curLength > maxLength) {
			//		maxStart = curStart;
					maxLength = curLength;
				}
				int newStart = curChars[ch] + 1;
				for (int k = curStart; k < newStart; k++) {
					curChars.erase(s[k]);
				}
				curStart = newStart;
				curLength = next - curStart;
			}
			curChars.insert(make_pair(ch, next));
			curLength++;
		}
		if (curLength > maxLength) {
		//	maxStart = curStart;
			maxLength = curLength;
		}

		return maxLength;
	}
};

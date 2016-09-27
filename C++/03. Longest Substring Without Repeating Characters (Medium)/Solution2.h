#pragma once
#include "LeetCode.h"
#include <unordered_map>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution2


class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		return lengthOfLongestSubstring_Ascii(s);
	}

	int lengthOfLongestSubstring_Ascii(string str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

		int /*maxStart = 0,*/ curStart = 0;
		int maxLength = 1, curLength = 1;
		int curChars[127];
		memset(curChars, 0, sizeof(curChars));
		curChars[str[0]] = 1;

		for (int next = 1; next < length; next++) {
			char ch = str[next];
			if (curChars[ch] > 0) {
				if (curLength > maxLength) {
			//		maxStart = curStart;
					maxLength = curLength;
				}
				int newStart = curChars[ch];
				for (int k = curStart; k < newStart; k++) {
					curChars[str[k]] = 0;
				}
				curStart = newStart;
				curLength = next - curStart;
			}
			curChars[ch] = next+1;
			curLength++;
		}
		if (curLength > maxLength) {
		//	maxStart = curStart;
			maxLength = curLength;
		}

		return maxLength;
	}

	int lengthOfLongestSubstring_Any(string str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

		int /*maxStart = 0,*/ curStart = 0;
		int maxLength = 1, curLength = 1;
		unordered_map<char, int> curChars;
		curChars.insert(make_pair(str[0], 0));

		for (int next = 1; next < length; next++) {
			char ch = str[next];
			if (curChars.find(ch) !=  curChars.end()) {
				if (curLength > maxLength) {
			//		maxStart = curStart;
					maxLength = curLength;
				}
				int newStart = curChars[ch] + 1;
				for (int k = curStart; k < newStart; k++) {
					curChars.erase(str[k]);
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

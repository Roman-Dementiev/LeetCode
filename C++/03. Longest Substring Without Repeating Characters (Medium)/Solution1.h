#pragma once
#include"LeetCode.h"
#include <unordered_set>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution1

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

//		int maxStart = 0;
		int maxLength = 1;
		for (int start = length-2; start >= 0; start--) {
			bool chars[127];
			memset(chars, 0, sizeof(chars));
			chars[str[start]] = true;
			int end;
			for (end = start+1; end < length; end++) {
				char ch = str[end];
				if (chars[ch])
					break;
				chars[ch] = true;
			}
			int len = end - start;
			if (len > maxLength) {
			//	maxStart = start;
				maxLength = len;
			}
		}
		return maxLength;
	}

	int lengthOfLongestSubstring_AnyChars(string str)
	{
		int length = str.length();
		if (length == 0)
			return 0;

//		int maxStart = 0;
		int maxLength = 1;
		for (int start = 0; start < length-1; start++) {
			unordered_set<char> chars;
			chars.insert(str[start]);
			int end;
			for (end = start+1; end < length; end++) {
				char ch = str[end];
				if (chars.find(ch) != chars.end())
					break;
				chars.insert(ch);
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

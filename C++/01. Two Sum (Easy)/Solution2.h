#pragma once
#include <unordered_map>
#include "LeetCode.h"

#ifdef Solution
#undef Solution
#endif
#define Solution Solution2


class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> index;

		for (int i = 0; i < nums.size(); i++) {
			int ni = nums[i];
			int n1 = target - ni;
			auto found = index.find(n1);
			if (found != index.end()) {
				return { found->second , i };
			}
			if (index.find(ni) == index.end()) {
				index.insert({ ni, i });
			}
		}

		return vector<int>();
	}
};

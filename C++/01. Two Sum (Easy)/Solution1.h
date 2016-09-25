#pragma once
#include "LeetCode.h"

#ifdef Solution
#undef Solution
#endif
#define Solution Solution1


class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		for (int i = 0, last = nums.size() - 1; i < last; i++) {
			for (int j = i + 1; j <= last; j++) {
				if (nums[i] + nums[j] == target) {
					return vector<int> {i, j };
				}
			}
		}

		return vector<int>();
	}
};

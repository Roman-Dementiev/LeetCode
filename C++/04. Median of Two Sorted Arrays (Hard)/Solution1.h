#pragma once
#include "LeetCode.h"
#include <algorithm>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution1


class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() == 0) {
			return FindMedianSortedArray(nums2);
		}
		if (nums2.size() == 0) {
			return FindMedianSortedArray(nums1);
		}

		int n = nums1.size() + nums2.size();
		int k = n / 2;

		int curr = 0, prev;
		for (int i1 = 0, i2 = 0; k >= 0; k--)
		{
			prev = curr;
			if (i1 == nums1.size()) {
				i2 += k;
				curr = nums2[i2];
				if (k > 0) {
					prev = nums2[i2 - 1];
				}
				break;
			}
			else if (i2 == nums2.size()) {
				i1 += k;
				curr = nums1[i1];
				if (k > 0) {
					prev = nums1[i1 - 1];
				}
				break;
			}

			if (nums1[i1] < nums2[i2]) {
				curr = nums1[i1++];
			} else {
				curr = nums2[i2++];
			}
		}

		if (n % 2 == 0) {
			return ((double)prev + (double)curr) / 2.0;
		} else {
			return curr;
		}
	}

	static double FindMedianSortedArray(const vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0.0;

		int mid = nums.size() / 2;
		double median = nums[mid];
		if (nums.size() % 2 == 0) {
			median = (median + nums[mid-1]) / 2.0;
		}
		return median;
	}
};

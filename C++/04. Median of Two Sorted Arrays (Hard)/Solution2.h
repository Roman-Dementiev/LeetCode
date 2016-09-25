#pragma once
#include "LeetCode.h"
#include <algorithm>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution2


class Solution2
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		double median;
		if (nums1.size() == 0) {
			median = FindMedianSortedArray(nums2);
		}
		else if (nums2.size() == 0) {
			median = FindMedianSortedArray(nums1);
		}
		else {
			int n = nums1.size() + nums2.size();
			int k = n / 2;
			median = FindKth(k, nums1, 0, nums1.size(), nums2, 0, nums2.size());
			if (n % 2 == 0) {
				median += FindKth(k-1, nums1, 0, nums1.size(), nums2, 0, nums2.size());
				median /= 2;
			}
		}

		return median;
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

	int FindKth(int k,
		const vector<int>& nums1, int start1, int count1,
		const vector<int>& nums2, int start2, int count2)
	{
		if (count1 == 0) {
			return nums2[start2 + k];
		}
		if (count2 == 0) {
			return nums1[start1 + k];
		}

		int k1 = count1 / 2;
		int k2 = count2 / 2;
		int n1 = nums1[start1 + k1];
		int n2 = nums2[start2 + k2];

		if (k == 0) {
			return min(nums1[start1], nums2[start2]);
		}
		if (k1 == 0 && k2 == 0) { // k == count1 == count2 == 1
			return max(n1, n2);
		}

		if (n1 < n2) {
			if (k <= k1 + k2) {
				return FindKth(k, nums1, start1, count1, nums2, start2, k2);
			} else {
				return FindKth(k - k1 - 1, nums1, start1 + k1 + 1, count1 - k1 - 1, nums2, start2, count2);
			}
		}
		else {
			if (k <= k1 + k2) {
				return FindKth(k, nums1, start1, k1, nums2, start2, count2);
			} else {
				return FindKth(k - k2 - 1, nums1, start1, count1, nums2, start2 + k2 + 1, count2 - k2 - 1);
			}
		}
	}
};

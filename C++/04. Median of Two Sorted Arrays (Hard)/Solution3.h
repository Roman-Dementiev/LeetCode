#pragma once
#include "LeetCode.h"
#include <algorithm>

#ifdef Solution
#undef Solution
#endif
#define Solution Solution3


class Solution
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
			median = FindKth(k, nums1.data(), nums1.size(), nums2.data(), nums2.size());
			if (n % 2 == 0) {
				median += FindKth(k-1, nums1.data(), nums1.size(), nums2.data(), nums2.size());
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

	int FindKth(int k, const int* nums1, int count1, const int* nums2, int count2)
	{
		if (count1 == 0) {
			return nums2[k];
		}
		if (count2 == 0) {
			return nums1[k];
		}

		for (;;)
		{
			if (k == 0) {
				return min(*nums1, *nums2);
			}
			int k1 = count1 / 2;
			int k2 = count2 / 2;
			int n1 = nums1[k1];
			int n2 = nums2[k2];

			if (k1 == 0 && k2 == 0) { // k == count1 == count2 == 1
				return max(n1, n2);
			}

			if (n1 < n2) {
				if (k <= k1 + k2) {
					count2 = k2;
				} else {
					k1++;
					k -= k1;
					nums1 += k1;
					count1 -= k1;
				}
			}
			else {
				if (k <= k1 + k2) {
					count1 = k1;
				} else {
					k2++;
					k -= k2;
					nums2 += k2;
					count2 -= k2;
				}
			}
		}
	}
};

using System;
using System.Diagnostics;

namespace LeetCode
{
	public class Solution1
	{
		double FindMedianSortedArray(int[] nums)
		{
			if (nums == null || nums.Length == 0)
				return 0.0;

			int mid = nums.Length / 2;
			double median = nums[mid];
			if (nums.Length % 2 == 0) {
				median = (median + nums[mid - 1]) / 2.0;
			}
			return median;
		}

		public int FindKth(int k, int[] nums1, int[] nums2, out int prev)
		{
			Debug.Assert(k >= 0 && k < nums1.Length + nums2.Length);

			prev = 0;
			int num = 0,  i1 = 0, i2 = 0;
			while (k >= 0)
			{
				prev = num;
				if (i1 == nums1.Length) {
					if (k > 0) prev = nums2[i2+k-1];
					return nums2[i2+k];
				}
				if (i2 == nums2.Length) {
					if (k > 0) prev = nums1[i1+k-1];
					return nums1[i1+k];
				}
				if (nums1[i1] < nums2[i2]) {
					num = nums1[i1++];
				} else {
					num = nums2[i2++];
				}
				k--;
			}
			return num;
		}

		public double FindMedianSortedArrays(int[] nums1, int[] nums2)
		{
			if (nums1 == null || nums1.Length == 0) {
				return FindMedianSortedArray(nums2);
			}
			if (nums2 == null || nums2.Length == 0) {
				return FindMedianSortedArray(nums1);
			}

			int n = nums1.Length + nums2.Length;
			int prev, num = FindKth(n / 2, nums1, nums2, out prev);

			if (n % 2 == 0) {
				return ((double)num + (double)prev) / 2.0;
			} else {
				return num;
			}
		}
	}
}

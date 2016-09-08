using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
	class Program
	{
		static void Main(string[] args)
		{
			var tests = new Nums2Test<double>[] {
				new Nums2Test<double>(null, null)
			};

			var sol = new Solution();
			sol.RunTests(tests, sol.FindMedianSortedArrays);
		}
	}

	public partial class Solution
	{
		double FindMedianSortedArray(int[] nums)
		{
			if (nums == null || nums.Length == 0)
				return 0.0;

			int mid = nums.Length / 2;
			if (nums.Length % 2 == 0) {
				return ((double)nums[mid - 1] + (double)nums[mid]) / 2.0;
			} else {
				return nums[mid];
			}
		}

		public double FindMedianSortedArraysWithMerge(int[] nums1, int[] nums2)
		{
			if (nums1 == null || nums1.Length == 0) {
				return FindMedianSortedArray(nums2);
			}
			if (nums2 == null || nums2.Length == 0) {
				return FindMedianSortedArray(nums1);
			}

			int[] nums = new int[nums1.Length + nums2.Length];
			int i = 0, i1 = 0, i2 = 0;
			for (;;) {
				if (i1 == nums1.Length) {
					while (i2 < nums2.Length) {
						nums[i++] = nums2[i2++];
					}
					break;
				}
				if (i2 == nums2.Length) {
					while (i1 < nums1.Length) {
						nums[i++] = nums1[i1++];
					}
					break;
				}

				if (nums1[i1] < nums2[i2]) {
					nums[i++] = nums1[i1++];
				} else {
					nums[i++] = nums2[i2++];
				}
			}

			return FindMedianSortedArray(nums);
		}

		public int FindKth(int[] nums1, int start1, int count1,
							int[] nums2, int start2, int count2,
							int k)
		{
			if (count1 == 0) {
				return nums2[start2];
			}
			if (count2 == 0) {
				return nums1[start1];
			}

			int k1 = count1 / 2;
			int k2 = count2 / 2;
			int n1 = nums1[start1 + k1];
			int n2 = nums2[start2 + k2];

			if (n1 < n2) {
				return FindKth(nums1, k1, count1 - k1, nums2, 0, k2 + 1, k - k1);
			} else {
				return FindKth(nums1, 0, k1 + 1, nums2, k2, count1 - k2, k - k2);
			}
		}

		public double FindMedianSortedArrays(int[] nums1, int[] nums2)
		{
			if (nums1 == null || nums1.Length == 0) {
				return FindMedianSortedArray(nums2);
			}
			if (nums2 == null || nums2.Length == 0) {
				return FindMedianSortedArray(nums1);
			}

			int len = nums1.Length + nums2.Length;
			int k = len / 2;
			if (len % 2 == 0) {
				int n1 = FindKth(nums1, 0, nums1.Length, nums2, 0, nums2.Length, k);
				int n2 = FindKth(nums1, 0, nums1.Length, nums2, 0, nums2.Length, k-1);
				return ((double)n1 + (double)n2) / 2.0;
			} else {
				int n = FindKth(nums1, 0, nums1.Length, nums2, 0, nums2.Length, k);
				return n;
			}
		}
	}
}

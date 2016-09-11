using System;
using System.Diagnostics;
using TestSample = LeetCode.TestSample<int[], int[], double>;

namespace LeetCode
{
	public class Solution2
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

		public int FindKth(int k,
							int[] nums1, int start1, int count1,
							int[] nums2, int start2, int count2)
		{
			Debug.Assert(start1 >= 0 && count1 >= 0 && start1 + count1 <= nums1.Length);
			Debug.Assert(start2 >= 0 && count2 >= 0 && start2 + count2 <= nums2.Length);
			Debug.Assert(k >= 0 && count1 + count2 > 0 && k < count1 + count2);

			Debug.WriteLine("FindKth: k={0} {1} {2}", k,
				TestSample.ToString(nums1, start1, count1),
				TestSample.ToString(nums2, start2, count2));

			if (count1 == 0) {
				Debug.WriteLine("       => {0}", nums2[start2+k]);
				return nums2[start2+k];
			}
			if (count2 == 0) {
				Debug.WriteLine("       => {0}", nums1[start1+k]);
				return nums1[start1+k];
			}

			int k1 = count1 / 2;
			int k2 = count2 / 2;
			int n1 = nums1[start1 + k1];
			int n2 = nums2[start2 + k2];
			Debug.WriteLine("       : k1={0} n1={1} k2={2} n2={3}", k1, n1, k2, n2);

			if (k == 0) {
				Debug.WriteLine("       => {0}", Math.Min(nums1[start1], nums2[start2]));
				return Math.Min(nums1[start1], nums2[start2]);
			}
			if (k1 == 0 && k2 == 0) { // k == count1 == count2 == 1
				Debug.WriteLine("       => {0}", Math.Max(n1, n2));
				return Math.Max(n1, n2);
			}

			if (n1 < n2) {
				if (k <= k1 + k2) {
					return FindKth(k, nums1, start1, count1, nums2, start2, k2);
				} else {
					return FindKth(k-k1-1, nums1, start1+k1+1, count1-k1-1, nums2, start2, count2);
				}
			} else {
				if (k <= k1 + k2) {
					return FindKth(k, nums1, start1, k1, nums2, start2, count2);
				} else {
					return FindKth(k-k2-1, nums1, start1, count1, nums2, start2+k2+1, count2-k2-1);
				}
			}
		}

		public double FindMedianSortedArrays(int[] nums1, int[] nums2)
		{
			Debug.WriteLine("FindMedian: {0} {1}", TestSample.ToString(nums1), TestSample.ToString(nums2));

			double median;
			if (nums1 == null || nums1.Length == 0) {
				median = FindMedianSortedArray(nums2);
			} else if (nums2 == null || nums2.Length == 0) {
				median = FindMedianSortedArray(nums1);
			} else {
				int n = nums1.Length + nums2.Length;
				int k = n/ 2;
				median = FindKth(k, nums1, 0, nums1.Length, nums2, 0, nums2.Length);
				if (n % 2 == 0) {
					median += FindKth(k-1, nums1, 0, nums1.Length, nums2, 0, nums2.Length);
					median /= 2;
				}
			}

			Debug.WriteLine("=> {0}\n", median);
			return median;
		}
	}
}

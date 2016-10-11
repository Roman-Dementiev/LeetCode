/**
 * 
 */
package LeetCode.MedianOfTwoSortedArrays;

/**
 * @author Roman Dementiev
 *
 */

public class Solution2
{
    public double findMedianSortedArrays(int[] nums1, int[] nums2)
	{
		double median;
		if (nums1 == null || nums1.length == 0) {
			median = findMedianSortedArray(nums2);
		}
		else if (nums2 == null || nums2.length == 0) {
			median = findMedianSortedArray(nums1);
		}
		else {
			int n = nums1.length + nums2.length;
			int k = n / 2;
			median = findKth(k, nums1, 0, nums1.length, nums2, 0, nums2.length);
			if (n % 2 == 0) {
				median += findKth(k-1, nums1, 0, nums1.length, nums2, 0, nums2.length);
				median /= 2;
			}
		}

		return median;
	}

	static double findMedianSortedArray(int[] nums)
	{
		if (nums == null || nums.length == 0)
			return 0.0;

		int mid = nums.length / 2;
		double median = nums[mid];
		if (nums.length % 2 == 0) {
			median = (median + nums[mid-1]) / 2.0;
		}
		return median;
	}

	int findKth(int k,
		int[] nums1, int start1, int count1,
		int[] nums2, int start2, int count2)
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
			return Math.min(nums1[start1], nums2[start2]);
		}
		if (k1 == 0 && k2 == 0) { // k == count1 == count2 == 1
			return Math.max(n1, n2);
		}

		if (n1 < n2) {
			if (k <= k1 + k2) {
				return findKth(k, nums1, start1, count1, nums2, start2, k2);
			} else {
				return findKth(k - k1 - 1, nums1, start1 + k1 + 1, count1 - k1 - 1, nums2, start2, count2);
			}
		}
		else {
			if (k <= k1 + k2) {
				return findKth(k, nums1, start1, k1, nums2, start2, count2);
			} else {
				return findKth(k - k2 - 1, nums1, start1, count1, nums2, start2 + k2 + 1, count2 - k2 - 1);
			}
		}
	}
}

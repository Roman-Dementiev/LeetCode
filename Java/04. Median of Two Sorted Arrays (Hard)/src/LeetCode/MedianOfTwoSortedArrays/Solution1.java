/**
 * 
 */
package LeetCode.MedianOfTwoSortedArrays;

/**
 * @author Roman Dementiev
 *
 */

public class Solution1
{
    public double findMedianSortedArrays(int[] nums1, int[] nums2)
    {
		if (nums1 == null || nums1.length == 0) {
			return findMedianSortedArray(nums2);
		}
		else if (nums2 == null || nums2.length == 0) {
			return findMedianSortedArray(nums1);
		}

		int n = nums1.length + nums2.length;
		int k = n / 2;

		int curr = 0, prev = 0;
		for (int i1 = 0, i2 = 0; k >= 0; k--)
		{
			prev = curr;
			if (i1 == nums1.length) {
				i2 += k;
				curr = nums2[i2];
				if (k > 0) {
					prev = nums2[i2 - 1];
				}
				break;
			}
			else if (i2 == nums2.length) {
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
}


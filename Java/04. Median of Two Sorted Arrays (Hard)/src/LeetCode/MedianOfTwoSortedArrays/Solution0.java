/**
 * 
 */
package LeetCode.MedianOfTwoSortedArrays;

/**
 * @author Roman
 *
 */
public class Solution0
{
    public double findMedianSortedArrays(int[] nums1, int[] nums2)
    {
		if (nums1 == null || nums1.length == 0) {
			return findMedianSortedArray(nums2);
		}
		if (nums2 == null || nums2.length == 0) {
			return findMedianSortedArray(nums1);
		}
		
		
		int[] nums = merge(nums1, nums2);
		return findMedianSortedArray(nums);
    }
    
    public int[] merge(int[] nums1, int[] nums2)
    {
    	int[] nums = new int[nums1.length+nums2.length];
    	
    	int i = 0, i1 = 0, i2 = 0;
    	while (i1 < nums1.length && i2 < nums2.length)
    	{
    		if (nums1[i1] < nums2[i2]) {
    			nums[i++] = nums1[i1++];
    		} else {
    			nums[i++] = nums2[i2++];
    		}
    	}
    	while (i1 < nums1.length) {
			nums[i++] = nums1[i1++];
    	}
    	while (i2 < nums2.length) {
			nums[i++] = nums2[i2++];
    	}
    	
    	return nums;
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

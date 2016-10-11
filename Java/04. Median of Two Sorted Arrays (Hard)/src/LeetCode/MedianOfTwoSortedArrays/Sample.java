/**
 * 
 */
package LeetCode.MedianOfTwoSortedArrays;

import LeetCode.TestSample;

/**
 * @author Roman Dementiev
 *
 */
public class Sample extends TestSample<Double, int[], int[], Void>
{
	public Sample(int[] nums1, int[] nums2)
	{
		super(nums1, nums2, null, null);
	}
	
	public Sample(int[] nums1, int[] nums2, double expected)
	{
		super(nums1, nums2, null, expected);
	}
}

/**
 * 
 */
package LeetCode.TwoSum;

/**
 * @author Roman
 *
 */
public class Solution1
{
    public int[] twoSum(int[] nums, int target)
    {
		if (nums == null)
			return null;

		for (int i = 0, last = nums.length-1; i < last; i++) {
			for (int j = i + 1; j <= last; j++) {
				if (nums[i] + nums[j] == target) {
					return new int[] { i, j };
				}
			}
		}

		return new int[0];
    }
}

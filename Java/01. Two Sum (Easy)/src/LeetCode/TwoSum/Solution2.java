package LeetCode.TwoSum;
import java.util.HashMap;


public class Solution2
{
	public int[] twoSum(int[] nums, int target)
	{
		if (nums == null)
			return null;

		HashMap<Integer, Integer> index = new HashMap<Integer, Integer>();

		for (int i = 0; i < nums.length; i++) {
			int ni = nums[i];
			int n1 = target - ni;
			if (index.containsKey(n1)) {
				return new int[] {index.get(n1) , i};
			}
			if (!index.containsKey(ni)) {
				index.put(ni, i);
			}
		}

		return new int[0];
	}
}

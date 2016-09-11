using System;

namespace LeetCode
{
	public class Solution
	{
		public int[] TwoSum(int[] nums, int target)
		{
			if (nums == null)
				return null;

			for (int i = 0, last = nums.Length - 1; i < last; i++) {
				for (int j = i + 1; j <= last; j++) {
					if (nums[i] + nums[j] == target)
						return new int[2] { i, j };
				}
			}

			return null;
		}
	}
}

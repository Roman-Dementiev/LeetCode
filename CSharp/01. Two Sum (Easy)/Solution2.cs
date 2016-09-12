using System;
using System.Collections.Generic;

namespace LeetCode
{
	public class Solution2
	{
		public int[] TwoSum(int[] nums, int target)
		{
			if (nums == null)
				return null;

			var index = new Dictionary<int, int>();

			for (int i = 0; i < nums.Length; i++) {
				int ni = nums[i];
				int n1 = target - ni;
				if (index.ContainsKey(n1)) {
					return new int[] {index[n1] , i };
				}
				if (!index.ContainsKey(ni)) {
					index.Add(ni, i);
				}
			}

			return null;
		}
	}
}

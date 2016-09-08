using System;
using TestSample = LeetCode.TestSample<int[], int, int[]>;

namespace LeetCode
{
	class TwoSum
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample(new int[] { 2, 7, 11, 15 }, 9, new int[] {0, 1}),
				new TestSample(new int[] { 3, 2, 4 }, 6, new int[] {1, 2}),
				new TestSample(null, 0)
			};

			var sol = new Solution();
			sol.RunTests(tests, sol.TwoSum);
		}
	}

	public partial class Solution
	{
		public int[] TwoSum(int[] nums, int target)
		{
			if (nums == null)
				return null;

			for (int i = 0, last = nums.Length-1; i < last; i++) {
				for (int j = i + 1; j <= last; j++) {
					if (nums[i] + nums[j] == target)
						return new int[2] { i, j };
				}
			}

			return null;
		}
	}
}

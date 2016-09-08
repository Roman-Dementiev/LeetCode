using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
	class Program
	{
		static void Main(string[] args)
		{
			var tests = new NumsToNumsTest[] {
				new NumsToNumsTest(new int[] { 2, 7, 11, 15 }, 9, new int[] {0, 1}),
				new NumsToNumsTest(new int[] { 3, 2, 4 }, 6, new int[] {1, 2}),
				new NumsToNumsTest(null, 0)
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

			for (int i = 0; i < nums.Length-1; i++) {
				for (int j = i + 1; j < nums.Length; j++) {
					if (nums[i] + nums[j] == target)
						return new int[2] { i, j };
				}
			}

			return null;
		}
	}
}

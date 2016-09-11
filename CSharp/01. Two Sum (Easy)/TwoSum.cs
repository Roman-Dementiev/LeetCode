using System;
using TestSample = LeetCode.TestSample<int[], int, int[]>;

namespace LeetCode
{
	class TwoSum: TestProgram
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample(new int[] { 2, 7, 11, 15 }, 9, new int[] {0, 1}),
				new TestSample(new int[] { 3, 2, 4 }, 6, new int[] {1, 2}),
				new TestSample(null, 0)
			};

			var sol = new Solution();
			RunTests(tests, sol.TwoSum);
		}
	}

}

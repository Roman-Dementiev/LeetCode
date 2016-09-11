using System;
using System.Diagnostics;
using TestSample = LeetCode.TestSample<int[], int[], double>;


namespace LeetCode
{
	class MedianOfTwoSortedArrays : TestProgram
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample(new int[] { 100001 }, new int[] { 100000 }, 100000.5),
				new TestSample(new int[] { 1, 3 }, new int[] { 2 }, 2),
				new TestSample(new int[] { 1, 2 }, new int[] { 3, 4 }, 2.5),
				new TestSample(new int[] { 1, 2 }, new int[] { 1, 2, 3 }, 2),
				new TestSample(new int[] { 1, 2, 3 }, new int[] { 1, 2 }, 2),
				new TestSample(new int[] { 1 }, new int[] { 2, 3, 4 }, 2.5),
				new TestSample(new int[] { 1, 1, 1 }, new int[] { 1, 1, 1 }, 1),
				new TestSample(new int[] { 2, 3, 4, 5, 6 }, new int[] { 1 }, 3.5),
				new TestSample(new int[] { 1, 2 }, new int[] { }, 1.5),
				new TestSample(new int[] { 2 }, new int[] { 1, 3, 4 }, 2.5),
				new TestSample(new int[] { 3 }, new int[] { 1, 2, 4 }, 2.5),
				new TestSample(new int[] { 5 }, new int[] { 1, 2, 3, 4, 6 }, 3.5),
				new TestSample(new int[] { }, new int[] { 3, 4 }, 3.5),
				new TestSample(null, null)
			};

			var sol = new Solution2();
			RunTests(tests, sol.FindMedianSortedArrays);
		}
	}

}

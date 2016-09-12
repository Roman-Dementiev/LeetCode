using System;
using TestSample = LeetCode.TestSample<LeetCode.ListNode, LeetCode.ListNode, LeetCode.ListNode>;


namespace LeetCode
{
	class TwoSumNonReversed : TestProgram
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample(
					new ListNode(3, new ListNode(4, new ListNode(2))),
					new ListNode(4, new ListNode(6, new ListNode(5))),
					new ListNode(8, new ListNode(0, new ListNode(7)))
				),
				new TestSample(
					new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(1)))),
					new ListNode(9),
					new ListNode(1, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0)))))
				),
				new TestSample(
					new ListNode(3, new ListNode(4, new ListNode(2))),
					null,
					new ListNode(3, new ListNode(4, new ListNode(2)))
				),
				new TestSample(
					null,
					new ListNode(4, new ListNode(6, new ListNode(5))),
					new ListNode(4, new ListNode(6, new ListNode(5)))
				),
				new TestSample(null, null, null)
			};

			var sol = new Solution();
			RunTests(tests, sol.AddTwoNumbers);
		}
	}

}

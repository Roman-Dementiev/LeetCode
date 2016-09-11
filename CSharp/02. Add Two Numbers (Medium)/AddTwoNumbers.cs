using System;
using TestSample = LeetCode.TestSample<LeetCode.ListNode, LeetCode.ListNode, LeetCode.ListNode>;


namespace LeetCode
{
	class AddTwoNumbers : TestProgram
	{
		static void Main(string[] args)
		{
			var tests = new TestSample[] {
				new TestSample(
					new ListNode(2, new ListNode(4, new ListNode(3))),
					new ListNode(5, new ListNode(6, new ListNode(4))),
					new ListNode(7, new ListNode(0, new ListNode(8)))
				),
				new TestSample(
					new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(9)))),
					new ListNode(9),
					new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1)))))
				),
				new TestSample(
					new ListNode(2, new ListNode(4, new ListNode(3))),
					null,
					new ListNode(2, new ListNode(4, new ListNode(3)))
				),
				new TestSample(
					null,
					new ListNode(5, new ListNode(6, new ListNode(4))),
					new ListNode(5, new ListNode(6, new ListNode(4)))
				),
				new TestSample(null, null, null)
			};

			var sol = new Solution();
			RunTests(tests, sol.AddTwoNumbers);
		}
	}

}

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
			var tests = new ListToListTest[] {
				new ListToListTest(
					new ListNode(2, new ListNode(4, new ListNode(3))),
					new ListNode(5, new ListNode(6, new ListNode(4))),
					new ListNode(7, new ListNode(0, new ListNode(8)))
				),
				new ListToListTest(
					new ListNode(2, new ListNode(4, new ListNode(3))),
					null,
					new ListNode(2, new ListNode(4, new ListNode(3)))
				),
				new ListToListTest(
					null,
					new ListNode(5, new ListNode(6, new ListNode(4))),
					new ListNode(5, new ListNode(6, new ListNode(4)))
				),
				new ListToListTest(null, null, null)
			};

			var sol = new Solution();
			sol.RunTests(tests, sol.AddTwoNumbers);
		}
	}

	public partial class Solution
	{
		public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
		{
			int carry = 0;
			ListNode dummy = new ListNode(0);
			ListNode node = dummy;
			while (l1 != null && l2 != null) {
				int sum = l1.val + l2.val + carry;
				if (sum >= 10) {
					sum -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
				node = node.next = new ListNode(sum);
				l1 = l1.next;
				l2 = l2.next;
			}

			if (l1 == null)
				l1 = l2;

			while (l1 != null) {
				int sum = l1.val + carry;
				if (sum >= 10) {
					sum -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
				node = node.next = new ListNode(sum);
				l1 = l1.next;
			}

			if (carry > 0) {
				node.next = new ListNode(carry);
			}

			return dummy.next;
		}

		public ListNode AddTwoNumbers1(ListNode l1, ListNode l2)
		{
			if (l1 == null)
				return l2;
			if (l2 == null)
				return l1;

			ListNode head = new ListNode(0);
			ListNode next = head;
			ListNode prev = null;

			while (l1 != null || l2 != null) {
				if (next == null) {
					next = new ListNode(0);
					prev.next = next;
				}

				int val = next.val;
				if (l1 == null) {
					val += l2.val;
					l2 = l2.next;
				} else if (l2 == null) {
					val += l1.val;
					l1 = l1.next;
				} else {
					val += l1.val + l2.val;
					l1 = l1.next;
					l2 = l2.next;
				}

				if (val < 10) {
					next.val = val;
					prev = next;
					next = null;
				} else {
					next.val = val - 10;
					prev = next;
					prev.next = next = new ListNode(1);
				}
			}

			return head;
		}
	}
}

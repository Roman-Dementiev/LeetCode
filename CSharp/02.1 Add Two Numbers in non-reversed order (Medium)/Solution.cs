using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
	class Solution
	{
		public ListNode AddSumNode(ListNode head, int val1, int val2, ref int carry)
		{
			int sum = val1 + val2 + carry;
			if (sum >= 10) {
				sum -= 10;
				carry = 1;
			} else {
				carry = 0;
			}
			ListNode node = new ListNode(sum);
			node.next = head;
			return node;
		}

		public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
		{
			l1 = Reverse(l1);
			l2 = Reverse(l2);
			return AddAndReverse(l1, l2);
		}

		public ListNode Reverse(ListNode head)
		{
			ListNode prev = null;
			ListNode curr = head;
			while (curr != null) {
				ListNode next = curr.next;
				curr.next = prev;
				prev = curr;
				curr = next;
			}
			return prev;
		}

		public ListNode AddAndReverse(ListNode l1, ListNode l2)
		{
			int carry = 0;
			ListNode head = null;
			ListNode prev1 = null;
			ListNode prev2 = null;
			while (l1 != null && l2 != null) {
				head = AddSumNode(head, l1.val, l2.val, ref carry);
				ListNode next1 = l1.next;
				ListNode next2 = l2.next;
				l1.next = prev1;
				l2.next = prev2;
				prev1 = l1;
				prev2 = l2;
				l1 = next1;
				l2 = next2;
			}

			if (l1 == null) {
				l1 = l2;
				prev1 = prev2;
			}

			while (l1 != null) {
				head = AddSumNode(head, l1.val, 0, ref carry);
				ListNode next1 = l1.next;
				l1.next = prev1;
				prev1 = l1;
				l1 = next1;
			}

			if (carry > 0) {
				head = AddSumNode(head, 0, 0, ref carry);
			}

			return head;
		}
	}
}

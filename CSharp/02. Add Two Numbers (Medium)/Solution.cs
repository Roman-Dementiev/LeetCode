using System;

namespace LeetCode
{
	public class Solution
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

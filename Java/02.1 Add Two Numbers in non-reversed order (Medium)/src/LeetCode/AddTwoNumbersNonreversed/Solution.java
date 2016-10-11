/**
 * 
 */
package LeetCode.AddTwoNumbersNonreversed;

import LeetCode.*;

/**
 * @author Roman Dementiev
 *
 */
public class Solution
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
		l1 = reverse(l1);
		l2 = reverse(l2);
		return addAndReverse(l1, l2);
    }

	public ListNode reverse(ListNode head)
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

	public ListNode addAndReverse(ListNode l1, ListNode l2)
	{
		ListNode carry = new ListNode(0);
		ListNode head = null;
		ListNode prev1 = null;
		ListNode prev2 = null;
		while (l1 != null && l2 != null) {
			head = addSumNode(head, l1.val, l2.val, carry);
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
			head = addSumNode(head, l1.val, 0, carry);
			ListNode next1 = l1.next;
			l1.next = prev1;
			prev1 = l1;
			l1 = next1;
		}

		if (carry.val > 0) {
			head = addSumNode(head, 0, 0, carry);
		}

		return head;
	}

	public ListNode addSumNode(ListNode head, int val1, int val2, ListNode carry)
	{
		int sum = val1 + val2 + carry.val;
		if (sum >= 10) {
			sum -= 10;
			carry.val = 1;
		} else {
			carry.val = 0;
		}
		ListNode node = new ListNode(sum);
		node.next = head;
		return node;
	}

}

/**
 * 
 */
package LeetCode.AddTwoNumbers;

import LeetCode.ListNode;


/**
 * @author Roman Dementiev
 *
 */

public class Solution
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
		ListNode dummy = new ListNode(0);
		ListNode carry = new ListNode(0);
		ListNode last = dummy;
		while (l1 != null && l2 != null) {
			last = addSumNode(last, l1.val, l2.val, carry);
			l1 = l1.next;
			l2 = l2.next;
		}

		if (l1 == null)
			l1 = l2;

		while (l1 != null) {
			last = addSumNode(last, l1.val, 0, carry);
			l1 = l1.next;
		}

		if (carry.val > 0) {
			last.next = carry;
		}

		return dummy.next;
    }

	public ListNode addSumNode(ListNode last, int val1, int val2, ListNode carry)
	{
		int sum = val1 + val2 + carry.val;
		if (sum >= 10) {
			sum -= 10;
			carry.val = 1;
		} else {
			carry.val = 0;
		}
		last.next = new ListNode(sum);
		return last.next;
	}
}

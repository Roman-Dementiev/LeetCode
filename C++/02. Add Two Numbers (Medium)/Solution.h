#pragma once
#include "LeetCode.h"

using ListNode = LeetCode::ListNode<int>;


class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0;
		ListNode* dummy = new ListNode(0);
		ListNode* node = dummy;
		while (l1 != nullptr && l2 != nullptr) {
			node = AddSumNode(node, l1->val, l2->val, carry);
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1 == nullptr)
			l1 = l2;

		while (l1 != nullptr) {
			node = AddSumNode(node, l1->val, 0, carry);
			l1 = l1->next;
		}

		if (carry > 0) {
			node->next = new ListNode(carry);
		}

		return dummy->next;
	}

	ListNode* AddSumNode(ListNode* last, int val1, int val2, int& carry)
	{
		int sum = val1 + val2 + carry;
		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		last->next = new ListNode(sum);
		return last->next;
	}
};


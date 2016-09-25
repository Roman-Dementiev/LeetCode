#pragma once
#include "LeetCode.h"

using ListNode = LeetCode::ListNode<int>;

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		l1 = Reverse(l1);
		l2 = Reverse(l2);
		return AddAndReverse(l1, l2);
	}

	ListNode* AddSumNode(ListNode* head, int val1, int val2, int &carry)
	{
		int sum = val1 + val2 + carry;
		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		ListNode* node = new ListNode(sum);
		node->next = head;
		return node;
	}

	ListNode* Reverse(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	ListNode* AddAndReverse(ListNode* l1, ListNode* l2)
	{
		int carry = 0;
		ListNode* head = nullptr;
		ListNode* prev1 = nullptr;
		ListNode* prev2 = nullptr;
		while (l1 != nullptr && l2 != nullptr) {
			head = AddSumNode(head, l1->val, l2->val, carry);
			ListNode* next1 = l1->next;
			ListNode* next2 = l2->next;
			l1->next = prev1;
			l2->next = prev2;
			prev1 = l1;
			prev2 = l2;
			l1 = next1;
			l2 = next2;
		}

		if (l1 == nullptr) {
			l1 = l2;
			prev1 = prev2;
		}

		while (l1 != nullptr) {
			head = AddSumNode(head, l1->val, 0,carry);
			ListNode* next = l1->next;
			l1->next = prev1;
			prev1 = l1;
			l1 = next;
		}

		if (carry > 0) {
			head = AddSumNode(head, 0, 0, carry);
		}

		return head;
	}
};


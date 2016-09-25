#include "LeetCode.h"

namespace LeetCode {

	template<typename T>
	List<T>::List(ListNode<T>* head)
	{
		dummy.next = head;
		last = &dummy;
		while (last->next != nullptr)
			last = last->next;
	}

	template<typename T>
	List<T>::List(const initializer_list<T> &il)
	{
		dummy.next = nullptr;
		last = &dummy;
		for (auto val : il) {
			last = last->next = new ListNode<T>(val);
		}
	}

	template<typename T>
	List<T>::List(const List& list)
	{
		dummy.next = nullptr;
		last = &dummy;
		ListNode<T>* node = list.Head();
		while (node != nullptr) {
			last = last->next = new ListNode<T>(node->val);
			node = node->next;
		}
	}

	template<typename T>
	List<T>::List(List<T>&& list)
	{
		dummy.next = list.dummy.next;
		last = list.last;
		list.dummy.next = list.last = nullptr;
	}

	template<typename T>
	List<T>::~List()
	{
		Clear();
	}

	template<typename T>
	bool List<T>::operator == (const List<T>& list) const
	{
		ListNode<T>* node1 = Head();
		ListNode<T>* node2 = list.Head();
		while (node1 != nullptr && node2 != nullptr)
		{
			if (node1->val != node2->val)
				return false;

			node1 = node1->next;
			node2 = node2->next;
		}

		return node1 == node2; // both nullptr
	}

	template<typename T>
	List<T>& List<T>::operator = (ListNode<T>* head)
	{
		Clear();
		dummy.next = head;
		last = &dummy;
		while (last->next != nullptr)
			last = last->next;

		return *this;
	}

	template<typename T>
	List<T>& List<T>::operator = (const List& list)
	{
		Clear();
		dummy.next = nullptr;
		last = &dummy;
		ListNode<T>* node = list.Head();
		while (node != nullptr) {
			last = last->next = new ListNode<T>(node->val);
			node = node->next;
		}
		return *this;
	}

	template<typename T>
	List<T>& List<T>::operator = (List&& list)
	{
		Clear();
		dummy.next = list.dummy.next;
		last = list.last;
		list.dummy.next = list.last = nullptr;
		return *this;
	}

	template<typename T>
	void List<T>::Clear()
	{
		for (ListNode<T>* node = dummy.next, *next; node != nullptr; node = next) {
			next = node->next;
			delete node;
		}

		dummy.next = nullptr;
		last = &dummy;
	}

	template<typename T>
	void List<T>::AddToEnd(ListNode<T>* nodes)
	{
		last->next = nodes;
		while (last->next != nullptr)
			last = last->next;
	}

	template<typename T>
	void List<T>::AddToHead(ListNode<T>* nodes)
	{
		ListNode<T>* head = dummy.next;
		dummy.next = nodes;
		while (nodes->next != nullptr)
			nodes = nodes->next;
		nodes->next = head;
	}

	template class List<int>;
	template class Range<int>;
}

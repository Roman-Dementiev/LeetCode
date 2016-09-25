#pragma once
#include <string>
#include <vector>
#include <functional>
#include <tuple>
#include <random>
#include <cassert>
#include <initializer_list>
#include "TestSamples.h"
#include "TestProgram.h"
#include "RandomSamples.h"
#pragma warning (disable:4018)


namespace LeetCode
{	
	enum class TestStatus
	{
		Unknown,
		Passed,
		Failed
	};

	/// <summary>
	/// Singly-linked list node
	/// </summary>
	template<class T>
	struct ListNode {
		T val;
		ListNode* next;
				
		/// <summary>
		/// Initializes a new instance of the <see cref="ListNode{T}"/> struct.
		/// </summary>
		ListNode() : next(nullptr) {}
		
		/// <summary>
		/// Initializes a new instance of the <see cref="ListNode{T}"/> struct.
		/// </summary>
		/// <param name="val">The value.</param>
		/// <param name="next">The next node.</param>
		ListNode(const T val, ListNode* next = nullptr) : val(val), next(next) {}
	};
	
	/// <summary>
	/// Singly-linked list
	/// </summary>
	template<class T>
	class List
	{
		ListNode<T> dummy;
		ListNode<T>* last;
	public:		
		/// <summary>
		/// Initializes a new instance of the <see cref="List"/> class.
		/// </summary>
		/// <param name="head">The head of the list.</param>
		List(ListNode<T>* head = nullptr);
		
		/// <summary>
		/// Initializes a new instance of the <see cref="List"/> class.
		/// </summary>
		/// <param name="il">The nodes values.</param>
		List(const initializer_list<T> &il);
		
		/// <summary>
		/// Initializes a new instance of the <see cref="List"/> class.
		/// </summary>
		/// <param name="list">The list to copy nodes from.</param>
		List(const List& list);
		
		/// <summary>
		/// Initializes a new instance of the <see cref="List"/> class.
		/// </summary>
		/// <param name="list">The list to move nodes from.</param>
		List(List<T>&& list);
		
		/// <summary>
		/// Finalizes an instance of the <see cref="List"/> class.
		/// </summary>
		~List();
		
		/// <summary>
		/// The first node of the list.
		/// </summary>
		/// <returns></returns>
		ListNode<T>* Head() const { return dummy.next; }
		
		/// <summary>
		/// The last node of the list.
		/// </summary>
		/// <returns></returns>
		ListNode<T>* Last() const { return last != &dummy ? last : nullptr; }
						
		/// <summary>
		/// Clears the list.
		/// </summary>
		void Clear();
		
		/// <summary>
		/// Adds nodes to the end of the list.
		/// </summary>
		/// <param name="nodes">The nodes.</param>
		void AddToEnd(ListNode<T>* nodes);
		
		/// <summary>
		/// Adds nodes to the head of the list.
		/// </summary>
		/// <param name="nodes">The nodes.</param>
		void AddToHead(ListNode<T>* nodes);
		
		/// <summary>
		/// Adds new node to the end of the list.
		/// </summary>
		/// <param name="val">The value of the node.</param>
		/// <returns></returns>
		List& operator >> (const T& val) {
			AddToEnd(new ListNode<T>(val));
			return *this;
		}

		/// <summary>
		/// Adds new node to the head of the list.
		/// </summary>
		/// <param name="val">The value of the node.</param>
		/// <returns></returns>
		List& operator << (const T& val) {
			AddToHead(new ListNode<T>(val));
			return *this;
		}

		bool operator == (const List& list) const;
		List& operator = (ListNode<T>* head);
		List& operator = (const List& list);
		List& operator = (List&& list);
};


	/// <summary>
	/// Range of array (vector)
	/// </summary>
	template<typename T>
	class Range
	{
		const vector<T>& array;
		const int start;
		const int length;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Range"/> class.
		/// </summary>
		/// <param name="array">The array.</param>
		/// <param name="start">The start index.</param>
		/// <param name="length">The length of the range.</param>
		Range(const vector<T>& array, int start, int length) :
			array(array),
			start(start),
			length(length)
		{}

		/// <summary>
		/// The array.
		/// </summary>
		/// <returns></returns>
		const std::vector<T>& Array() const { return array; }

		/// <summary>
		/// The start index.
		/// </summary>
		/// <returns></returns>
		const int Start() const { return start; }

		/// <summary>
		/// The length of the range.
		/// </summary>
		/// <returns></returns>
		const int Length() const { return length; }

		/// <summary>
		/// The element of range.
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		const T& operator [](size_t index) const { return array[start + index]; }

		/// <summary>
		/// The element of range.
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		const T& operator [](size_t index) { return array[start + index]; }
	};
} // namespace LeetCode

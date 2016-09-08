using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
	public partial class Solution
	{
		public void RunTests<TArg, TResult>(Test<TArg, TArg, TResult>[] tests, Func<TArg, TResult> func)
		{
			foreach (var test in tests) {
				test.result = func(test.arg1);
				Console.Out.WriteLine(test.ToString());
			}
		}

		public void RunTests<TArg1, TArg2, TResult>(Test<TArg1, TArg2, TResult>[] tests, Func<TArg1, TArg2, TResult> func)
		{
			foreach (var test in tests) {
				test.result = func(test.arg1, test.arg2);
				Console.Out.WriteLine(test.ToString());
			}
		}

		public void RunTests<TArg, TResult>(TArg[] tests, Func<TArg, TResult> func)
		{
			foreach (var test in tests) {
				TResult result = func(test);
				Console.Out.WriteLine("{0} => {1}");
			}
		}

		public void RunTests<TArg, TResult>(TArg[] tests, Func<TArg, TArg, TResult> func)
		{
			for (int i = 1; i < tests.Length; i += 2) {
				TResult result = func(tests[i - 1], tests[i]);
				Console.Out.WriteLine("({0}, {1}) => {2}");
			}
		}
	}


	public class Test<TArg1, TArg2, TResult>
	{
		public int nArgs;
		public TArg1 arg1;
		public TArg2 arg2;
		public TResult expected;
		public TResult result;

		public Test(int nArgs, TArg1 arg1, TArg2 arg2, TResult expected)
		{
			this.nArgs = nArgs;
			this.arg1 = arg1;
			this.arg2 = arg2;
			this.expected = expected;
			this.result = default(TResult);
		}

		public Test(TArg1 arg) :
			this(1, arg, default(TArg2), default(TResult))
		{}
		public Test(TArg1 arg1, TArg2 arg2) :
			this(2, arg1, arg2, default(TResult))
		{ }
		public Test(TArg1 arg, TResult expected) :
			this(1, arg, default(TArg2), expected)
		{ }
		public Test(TArg1 arg1, TArg2 arg2, TResult expected) :
			this(2, arg1, arg2, expected)
		{ }

		public virtual bool Success()
		{
			return expected == null || expected.Equals(result);
		}

		public virtual string ObjToString(object obj)
		{
			if (obj == null) return null;
 			if (obj.GetType() == typeof(string)) {
				return String.Format("\"{0}\"", obj);
			} else {
				return obj.ToString();
			}
		}
		public virtual string Arg1ToString() 
		{
			return ObjToString(arg1);
		}

		public virtual string Arg2ToString()
		{
			return ObjToString(arg2);
		}

		public virtual string ResultToString(TResult result)
		{
			return ObjToString(result);
		}

		public override string ToString()
		{
			string str = String.Empty;
			if (expected != null && !Success()) {
				str = String.Format("  Failed, expected: {0}", ResultToString(result));
			}

			if (nArgs == 2) {
				return String.Format("{0}, {1} => {2}{3}",
					Arg1ToString(), Arg2ToString(), ResultToString(result), str);
			} else {
				return String.Format("{0} => {1}{2}",
					Arg1ToString(), ResultToString(result), str);
			}
		}
	}


	public class NumsTest<TArg2, TResult> : Test<int[], TArg2, TResult>
	{
		public NumsTest(int[] nums) :
			base(nums)
		{ }
		public NumsTest(int[] nums, TArg2 arg2) :
			base(nums, arg2, default(TResult))
		{ }
		public NumsTest(int[] nums, TResult expected) :
			base(nums, default(TArg2), expected)
		{ }
		public NumsTest(int[] nums, TArg2 arg2, TResult expected) :
			base(nums, arg2, expected)
		{ }

		public static string NumsToString(int[] nums)
		{
			if (nums == null) return "null";
			if (nums.Length == 0) return "[]";

			StringBuilder sb = new StringBuilder("[");
			sb.Append(nums[0].ToString());
			for (int i = 1; i < nums.Length; i++) {
				sb.Append(" ");
				sb.Append(nums[i].ToString());
			}
			sb.Append("]");
			return sb.ToString();
		}

		public override string Arg1ToString()
		{
			return NumsToString(arg1);
		}
	}

	public class Nums1Test<TResult> : NumsTest<int, TResult>
	{
		public Nums1Test(int[] nums) :
			base(nums)
		{}
		public Nums1Test(int[] nums, int target) :
			base(nums, target, default(TResult))
		{}
		public Nums1Test(int[] nums, TResult expected) :
			base(nums, expected)
		{}
		public Nums1Test(int[] nums, int target, TResult expected) :
			base(nums, target, expected)
		{}
	}

	public class Nums2Test<TResult> : NumsTest<int[], TResult>
	{
		public Nums2Test(int[] nums1, int[] nums2) :
			base(nums1, nums2, default(TResult))
		{}
		public Nums2Test(int[] nums1, int[] nums2, TResult expected) :
			base(nums1, nums2, expected)
		{}

		public override string Arg2ToString()
		{
			return NumsToString(arg2);
		}
	}

	public class NumsToNumsTest : NumsTest<int, int[]>
	{
		public NumsToNumsTest(int[] nums) :
			base(nums)
		{}
		public NumsToNumsTest(int[] nums, int target) :
			base(nums, target)
		{}
		public NumsToNumsTest(int[] nums, int[] expected) :
			base(nums, expected)
		{}
		public NumsToNumsTest(int[] nums, int target, int[] expected) :
			base(nums, target, expected)
		{}

		public override bool Success()
		{
			if (expected != null) {
				if (result == null || result.Length != expected.Length)
					return false;

				for (int i = 0; i < result.Length; i++) {
					if (result[i] != expected[i])
						return false;
				}
			}
			return true;
		}

		public override string ResultToString(int[] result)
		{
			return NumsToString(result);
		}
	}


	/*
	 * Definition for singly-linked list.
	 */
	public class ListNode
	{
		public int val;
		public ListNode next;
		public ListNode(int x, ListNode n = null) { val = x; next = n;  }
	}


	public class ListTest<TResult> : Test<ListNode, ListNode, TResult>
	{
		public ListTest(ListNode head) :
			base(head)
		{ }
		public ListTest(ListNode head, ListNode arg2) :
			base(head, arg2, default(TResult))
		{ }
		public ListTest(ListNode head, TResult expected) :
			base(head, null, expected)
		{ }
		public ListTest(ListNode head, ListNode arg2, TResult expected) :
			base(head, arg2, expected)
		{ }

		public static string NodeToString(ListNode node)
		{
			if (node == null) return "null";
			return node.val.ToString();
		}

		public static string ListToString(ListNode head)
		{
			if (head == null) return "null";

			StringBuilder sb = new StringBuilder("{");
			sb.Append(head.val.ToString());
			for (ListNode node = head.next; node != null; node = node.next) {
				sb.Append(" -> ");
				sb.Append(node.val);
			}
			sb.Append("}");
			return sb.ToString();
		}

		public override string Arg1ToString()
		{
			return ListToString(arg1);
		}

		public override string Arg2ToString()
		{
			return ListToString(arg2);
		}
	}

	public class ListToListTest : ListTest<ListNode>
	{
		public ListToListTest(ListNode head) :
			base(head)
		{ }
		public ListToListTest(ListNode head, ListNode arg2, ListNode expected) :
			base(head, arg2, expected)
		{ }

		public override string ResultToString(ListNode result)
		{
			return ListToString(result);
		}

		public override bool Success()
		{
			ListNode l1 = result;
			ListNode l2 = expected;
			while (l1 != null && l2 != null) {
				if (l1.val != l2.val)
					return false;

				l1 = l1.next;
				l2 = l2.next;
			}

			return l1 == null && l2 == null;
		}
	}
}

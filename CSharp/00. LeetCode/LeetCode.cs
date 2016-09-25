using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
	/// <summary>
	/// Test status
	/// </summary>
	public enum TestStatus
	{
		None,
		Passed,
		Failed
	}

	/// <summary>
	/// Placeholder for unused second argument
	/// </summary>
	public enum Void { @void };

	/// <summary>
	/// Definition for singly-linked list
	/// </summary>
	public class ListNode
	{
		public int val;
		public ListNode next;
		public ListNode(int x, ListNode n = null) { val = x; next = n; }
	}

	/// <summary>
	/// class Solution
	/// </summary>
	public class TestProgram
	{
		/// <summary>
		/// Runs the tests.
		/// </summary>
		/// <typeparam name="TArg">The type of the argument.</typeparam>
		/// <typeparam name="TResult">The type of the result.</typeparam>
		/// <param name="tests">The test samples.</param>
		/// <param name="func">The test function.</param>
		public static void RunTests<TArg, TResult>(TestSample<TArg, Void, TResult>[] tests, Func<TArg, TResult> func)
		{
			foreach (var test in tests) {
				TResult result = func(test.Arg1);
				test.SetResult(result);
				Console.Out.WriteLine(test.ToString());
			}
		}

		/// <summary>
		/// Runs the tests.
		/// </summary>
		/// <typeparam name="TArg1">The type of the 1st argument.</typeparam>
		/// <typeparam name="TArg2">The type of the 2nd argument.</typeparam>
		/// <typeparam name="TResult">The type of the result.</typeparam>
		/// <param name="tests">The test samples.</param>
		/// <param name="func">The test function.</param>
		public static void RunTests<TArg1, TArg2, TResult>(TestSample<TArg1, TArg2, TResult>[] tests, Func<TArg1, TArg2, TResult> func)
		{
			foreach (var test in tests) {
				TResult result = func(test.Arg1, test.Arg2);
				test.SetResult(result);
				Console.Out.WriteLine(test.ToString());
			}
		}

		// <summary>
		// </summary>
		// <typeparam name = "TArg" > The type of the argument.</typeparam>
		// <typeparam name = "TResult" > The type of the result.</typeparam>
		// <param name = "tests" > The test arguments.</param>
		// <param name = "func" > The test function.</param>
		public static void RunTests<TArg, TResult>(TArg[] tests, Func<TArg, TResult> func)
		{
			foreach (var test in tests) {
				TResult result = func(test);
				Console.Out.WriteLine("{0} => {1}");
			}
		}

		// <summary>
		// Runs the tests.
		// </summary>
		// <typeparam name = "TArg" > The type of the arguments.</typeparam>
		// <typeparam name = "TResult" > The type of the result.</typeparam>
		// <param name = "tests" > The pairs of test argument.</param>
		// <param name = "func" > The test function.</param>
		public void RunTests<TArg, TResult>(TArg[] tests, Func<TArg, TArg, TResult> func)
		{
			for (int i = 1; i < tests.Length; i += 2) {
				TResult result = func(tests[i - 1], tests[i]);
				Console.Out.WriteLine("({0}, {1}) => {2}");
			}
		}
	}

	/// <summary>
	/// class TestSample
	/// </summary>
	/// <typeparam name="TArg1">The type of the 1st argument.</typeparam>
	/// <typeparam name="TArg2">The type of the optional 2nd argument.</typeparam>
	/// <typeparam name="TResult">The type of the result.</typeparam>
	public class TestSample<TArg1, TArg2, TResult>
	{
		/// <summary>
		/// Gets the number of arguments.
		/// </summary>
		/// <value>
		/// The number of arguments.
		/// </value>
		public int NumArgs { get; }

		/// <summary>
		/// Gets the first argument.
		/// </summary>
		/// <value>
		/// The arg1.
		/// </value>
		public TArg1 Arg1 { get; }

		/// <summary>
		/// Gets the second argument.
		/// </summary>
		/// <value>
		/// The arg2.
		/// </value>
		public TArg2 Arg2 { get; }

		/// <summary>
		/// Gets the expected result value.
		/// </summary>
		/// <value>
		/// The expected.
		/// </value>
		public object Expected { get; }

		/// <summary>
		/// Gets the test status.
		/// </summary>
		/// <value>
		/// The status.
		/// </value>
		public TestStatus Status { get; private set; }

		/// <summary>
		/// Gets or sets the result of test.
		/// </summary>
		/// <value>
		/// The result.
		/// </value>
		public TResult Result { get; private set; }

		/// <summary>
		/// Initializes a new instance of the <see cref="TestSample" /> class.
		/// </summary>
		/// <param name="nArgs">The n arguments.</param>
		/// <param name="arg1">The first argument.</param>
		/// <param name="arg2">The second argument.</param>
		/// <param name="expected">The expected result.</param>
		protected TestSample(int nArgs, TArg1 arg1, TArg2 arg2, object expected)
		{
			NumArgs = nArgs;
			Arg1 = arg1;
			Arg2 = arg2;
			Expected = expected;
			Status = TestStatus.None;
			Result = default(TResult);
		}

		/// <summary>
		/// Initializes a new instance of the <see cref="TestSample" /> class.value
		/// </summary>
		/// <param name="arg">The argument.</param>
		public TestSample(TArg1 arg) :
			this(1, arg, default(TArg2), null)
		{ }

		/// <summary>
		/// Initializes a new instance of the <see cref="TestSample" /> class.
		/// </summary>
		/// <param name="arg1">The first argument.</param>
		/// <param name="arg2">The second argument.</param>
		public TestSample(TArg1 arg1, TArg2 arg2) :
			this(2, arg1, arg2, null)
		{ }

		/// <summary>
		/// Initializes a new instance of the <see cref="TestSample" /> class.
		/// </summary>
		/// <param name="arg">The argument.</param>
		/// <param name="expected">The expected result value.</param>
		public TestSample(TArg1 arg, object expected) :
			this(1, arg, default(TArg2), expected)
		{ }

		/// <summary>
		/// Initializes a new instance of the <see cref="TestSample" /> class.
		/// </summary>
		/// <param name="arg1">The first argument.</param>
		/// <param name="arg2">The second argument.</param>
		/// <param name="expected">The expected.</param>
		public TestSample(TArg1 arg1, TArg2 arg2, TResult expected) :
					this(2, arg1, arg2, expected)
		{ }

		/// <summary>
		/// Sets the result.
		/// </summary>
		/// <param name="result">The result.</param>
		public void SetResult(TResult result)
		{
			Result = result;

			if (Expected != null) {
				Status = AreEqual(result, Expected) ? TestStatus.Passed : TestStatus.Failed;
			}
		}

		/// <summary>
		/// Returns a <see cref="System.String" /> that represents this instance.
		/// </summary>
		/// <returns>
		/// A <see cref="System.String" /> that represents this instance.
		/// </returns>
		public override string ToString()
		{
			string status = String.Empty;
			if (Status == TestStatus.Failed) {
				status = String.Format("  Failed, expected: {0}", ToString(Expected));

			}

			if (NumArgs == 2) {
				return String.Format("{0}, {1} => {2}{3}",
					ToString(Arg1), ToString(Arg2), ToString(Result), status);
			} else {
				return String.Format("{0} => {1}{2}",
					ToString(Arg1), ToString(Result), status);
			}
		}

		/// <summary>
		/// Returns a <see cref="System.String" /> that represents the range of array.
		/// </summary>
		/// <param name="array">The array.</param>
		/// <param name="start">The range start.</param>
		/// <param name="count">The range length.</param>
		/// <returns>
		/// A <see cref="System.String" /> that represents this instance.
		/// </returns>
		public static string ToString(Array array, int start, int length)
		{
			if (length == 0)
				return "[]";

			var sb = new StringBuilder("[");
			sb.Append(ToString(array.GetValue(start)));
			for (int i = 1; i < length; i++) {
				sb.Append(", ");
				sb.Append(ToString(array.GetValue(start+i)));
			}
			sb.Append("]");
			return sb.ToString();

		}

		/// <summary>
		/// Returns a <see cref="System.String" /> that represents the argument or result.
		/// </summary>
		/// <param name="obj">The object.</param>
		/// <returns>
		/// A <see cref="System.String" /> that represents the object.
		/// </returns>
		public static string ToString(object obj)
		{
			if (obj == null) return "null";

			if (obj is string) {
				return String.Format("\"{0}\"", obj);
			}

			if (obj is Array) {
				var array = obj as Array;
				return ToString(array, 0, array.Length);
			}

			if (obj is ListNode) {
				ListNode node = obj as ListNode;
				StringBuilder sb = new StringBuilder("{");
				sb.Append(node.val.ToString());
				while ((node = node.next) != null) {
					sb.Append(" -> ");
					sb.Append(node.val);
				}
				sb.Append("}");
				return sb.ToString();
			}

			return obj.ToString();
		}

		/// <summary>
		/// Checks if result and expected value are equal.
		/// </summary>
		/// <param name="result">The result.</param>
		/// <param name="expected">The expected value.</param>
		/// <returns></returns>
		public virtual bool AreEqual(object result, object expected)
		{
			if (result == null)
				return expected == null;

			if (result is Array) {
				var resultArray = result as Array;
				var expectedArray = expected as Array;
				if (expectedArray == null)
					return false;

				if (resultArray.Length != expectedArray.Length)
					return false;

				for (int i = 0; i < resultArray.Length; i++) {
					if (!AreEqual(resultArray.GetValue(i), expectedArray.GetValue(i)))
						return false;
				}

				return true;
			}

			if (result is ListNode) {
				ListNode l1 = result as ListNode;
				ListNode l2 = expected as ListNode;
				while (l1 != null && l2 != null) {
					if (l1.val != l2.val)
						return false;

					l1 = l1.next;
					l2 = l2.next;
				}

				return l1 == null && l2 == null;
			}

			return result.Equals(expected);
		}
	}

}

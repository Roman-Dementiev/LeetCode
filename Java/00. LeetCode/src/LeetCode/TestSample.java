/**
 * 
 */
package LeetCode;

/**
 * @author Roman Dementiev
 *
 */

public class TestSample<TResult, TArg1, TArg2, TArg3>
{
	protected TArg1 arg1;
	protected TArg2 arg2;
	protected TArg3 arg3;
	protected TResult expected;
	protected TResult result;
	protected TestStatus status;

	public TestSample(TArg1 arg1, TArg2 arg2, TArg3 arg3, TResult expected)
	{
		this.arg1 = arg1;
		this.arg2 = arg2;
		this.arg3 = arg3;
		this.result = null;
		this.expected = expected;
		result = null;
		status = TestStatus.Unknown;
	}	
	
	public TArg1 arg1() { return arg1; }
	public TArg2 arg2() { return arg2; }
	public TArg3 arg3() { return arg3; }
	public TResult expected() {return expected; }
	public TResult result() { return result; }
	public void setResult(TResult result) { this.result = result; }
	public void setStatus(TestStatus status) { this.status = status; }
	
	//@Override
	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		toString(sb, arg1);
		if (arg2 != null) {
			sb.append(", ");
			toString(sb, arg2);
		}
		if (arg3 != null) {
			sb.append(", ");
			toString(sb, arg3);
		}
		if (result != null) {
			sb.append(" => ");
			toString(sb, result);
		}
		if (status == TestStatus.Passed) {
			sb.append(" Passed");
		} else if (status == TestStatus.Failed) {
			sb.append(" Failed");
			if (expected != null) {
				sb.append(", expected ");
				toString(sb, expected);
			}
		}
		return sb.toString();
	}
	
	public static <T> void toString(StringBuilder sb, T obj)
	{
		if (obj == null)
		{
			sb.append("null");
		}
		else if (obj instanceof int[])
		{
			int[] array = (int[])obj;
			sb.append("[");
			if (array.length > 0) {
				sb.append(array[0]);
				for (int i = 1; i < array.length; i++) {
					sb.append(", ");
					sb.append(array[i]);
				}
			}
			sb.append("]");
		}
		else if (obj instanceof List || obj instanceof ListNode)
		{
			ListNode node;
			if (obj instanceof ListNode) {
				node = (ListNode)obj;
			} else {
				node = ((List)obj).head();
			}
			sb.append("{");
			if (node != null) {
				sb.append(node.val);
				while (node.next != null) {
					node = node.next;
					sb.append(", ");
					sb.append(node.val);
				}
			}
			sb.append("}");
		}
		else if (obj instanceof String)
		{
			sb.append("\"");
			sb.append(obj.toString());
			sb.append("\"");
		}
		else {
			sb.append(obj.toString());
		}
	}

	public TestStatus verify()
	{
		if (result == null || expected == null) {
			return TestStatus.Unknown;
		}
		
		return success() ? TestStatus.Passed : TestStatus.Failed;
	}
	
	public boolean success()
	{
		if (result instanceof int[])
		{
			int[] arrResult = (int[])result;
			int[] arrExpect = (int[])expected;			
			if (arrResult.length != arrExpect.length)
				return false;
			
			for (int i = 0; i < arrResult.length; i++) {
				if (arrResult[i] != arrExpect[i])
					return false;
			}
			return true;
		}
		
		return result.equals(expected);
	}
};




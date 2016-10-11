/**
 * 
 */
package LeetCode.TwoSum;

import LeetCode.TestSample;
import LeetCode.TestStatus;


/**
 * @author Roman Dementiev
 *
 */
public class Sample extends TestSample<int[], int[], Integer, Void>
{
	public Sample(int[] nums, Integer target, int[] expected) {
		super(nums, target, null, expected);
	}
	
	//@Override
	public TestStatus verify()
	{
		return success() ? TestStatus.Passed : TestStatus.Failed;
	}
	
	//@Override
	public boolean success()
	{
		if (result == null || result.length == 0) {
			return expected == null || expected.length == 0;
		}
		if (result.length != 2) {
			return false;
		}

		int i1 = result[0];
		int i2 = result[1];
		int n1 = arg1[i1];
		int n2 = arg1[i2];

		return n1 + n2 == arg2;	
	}
}


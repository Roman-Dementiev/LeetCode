/**
 * 
 */
package LeetCode.AddTwoNumbers;

import java.math.BigInteger;

import LeetCode.*;

/**
 * @author Roman Dementiev
 *
 */
public class Sample extends TestSample<DigitList, DigitList, DigitList, Void>
{
	public Sample(String str1, String str2)
	{
		this(str1, str2, null);
	}
	
	public Sample(String str1, String str2, String expected)
	{
		super(null, null, null, null);
		
		arg1 = new DigitList(str1, true);
		arg2 = new DigitList(str2, true);
		if (expected != null) {
			this.expected = new DigitList(expected, true);
		} else if (str1 != null || str2 != null){
			BigInteger n1 = arg1.getValue();
			BigInteger n2 = arg2.getValue();
			BigInteger sum = n1.add(n2);
			this.expected = new DigitList(sum, true);
		}
	}	

	public Sample(BigInteger n1, BigInteger n2)
	{
		super(null, null, null, null);		
		arg1 = new DigitList(n1, true);
		arg2 = new DigitList(n2, true);
		BigInteger sum = n1.add(n2);
		expected = new DigitList(sum, true);
	}
}

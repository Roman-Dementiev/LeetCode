/**
 * 
 */
package LeetCode.AddTwoNumbersNonreversed;

import LeetCode.*;
import java.math.BigInteger;

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
		
		arg1 = new DigitList(str1, false);
		arg2 = new DigitList(str2, false);
		if (expected != null) {
			this.expected = new DigitList(expected, false);
		} else if (str1 != null || str2 != null){
			BigInteger n1 = arg1.getValue();
			BigInteger n2 = arg2.getValue();
			BigInteger sum = n1.add(n2);
			this.expected = new DigitList(sum, false);
		}
	}	

	public Sample(BigInteger n1, BigInteger n2)
	{
		super(null, null, null, null);		
		arg1 = new DigitList(n1, false);
		arg2 = new DigitList(n2, false);
		BigInteger sum = n1.add(n2);
		expected = new DigitList(sum, false);
	}
}

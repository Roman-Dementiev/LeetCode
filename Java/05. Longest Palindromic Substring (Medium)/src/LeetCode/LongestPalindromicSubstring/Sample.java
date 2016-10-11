/**
 * 
 */
package LeetCode.LongestPalindromicSubstring;

import LeetCode.TestSample;

/**
 * @author Roman Dementiev
 *
 */
public class Sample extends TestSample<String, String, Void, Void>
{
	public Sample(String str) {
		super(str, null, null, null);
	}
	public Sample(String str, String expected) {
		super(str, null, null, expected);
	}	

	public boolean success()
	{
		return result.length() == expected.length();
	}
}

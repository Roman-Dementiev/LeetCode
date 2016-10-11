/**
 * 
 */
package LeetCode.LongestPalindromicSubstring;

import java.util.function.Function;
import LeetCode.RandomStrings;

/**
 * @author Roman
 *
 */
public class Randoms extends RandomStrings<Sample>
{
	Function<String, String> getResult;

	public Randoms(int maxLength, Function<String, String> getResult)
	{
		super(maxLength);
		this.getResult = getResult;
	}

	//@Override
	public Sample[] prepareSet(Sample[] samples, int nSamples, int N)
	{
		samples = super.prepareSet(samples, nSamples, N);
		nSamples = this.nSamples;
		N = this.N;

		for (int i = 0; i < nSamples; i++) {
			String result = getResult.apply(strings[i]);
			samples[i] = new Sample(strings[i], result);
		}
		
		return samples;
	}
}

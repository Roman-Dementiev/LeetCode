/**
 * 
 */
package LeetCode.LongestSubstringWithoutRepeatingCharacters;

import java.util.function.Function;
import LeetCode.RandomStrings;

/**
 * @author Roman Dementiev
 *
 */
public class Randoms extends RandomStrings<Sample>
{
	Function<String, Integer> getResult;

	public Randoms(int maxLength, Function<String, Integer> getResult)
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
			int result = getResult.apply(strings[i]);
			samples[i] = new Sample(strings[i], result);
		}
		
		return samples;
	}
}

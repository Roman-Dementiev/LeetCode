/**
 * 
 */
package LeetCode.AddTwoNumbersNonreversed;

import java.math.BigInteger;
import LeetCode.RandomSamples;
import LeetCode.AddTwoNumbers.Sample;

/**
 * @author Roman
 *
 */
public class Randoms extends RandomSamples<Sample>
{
	//@Override
	public Sample[] prepareSet(Sample[] samples, int nSamples, int N)
	{
		samples = super.prepareSet(samples, nSamples, N);
		nSamples = this.nSamples;
		N = this.N;
		
		BigInteger[]randomNums = new BigInteger[2*nSamples];
		
		if (N <= 0) {
			randomNumbers(randomNums, 100);
		} else {
			BigInteger min = BigInteger.ONE;
			BigInteger max = BigInteger.valueOf(N);
			while (min.compareTo(max) < 0) {
				min = min.multiply(BigInteger.TEN);
			}
			max = min.multiply(BigInteger.TEN).subtract(BigInteger.ONE);
			randomNumbers(randomNums, min, max);
		}

		for (int i = 0, k = 0; i < nSamples; i++) {
			BigInteger n1 = randomNums[k++];
			BigInteger n2 = randomNums[k++];

			samples[i] = new Sample(n1, n2);
		}
		
		return samples;
	}
}

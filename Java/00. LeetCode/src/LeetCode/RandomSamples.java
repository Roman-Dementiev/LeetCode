/**
 * 
 */
package LeetCode;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Random;


/**
 * @author Roman Dementiev
 *
 */

public abstract class RandomSamples<TSample>
{
	static int defaultSetSize = 1000;
	protected TSample[] samples = null;
	protected int nSamples = 0, N = 0;
	
	public RandomSamples() {}
	
	public int N() { return this.N; }
	public int numSamples() { return nSamples; }
	public TSample[] getSamples() { return samples; }
	
	public TSample[] prepareSet(TSample[] samples, int nSamples, int N)
	{
		if (nSamples <= 0) {
			nSamples = defaultSetSize;
		}
		if (samples.length < nSamples) {
			samples = Arrays.copyOf(samples, nSamples);
		}
		this.samples = samples;
		this.nSamples = nSamples;
		this.N = N > 0 ? N : 0;
		
		return samples;
	}
	
	public static void randomNumbers(int[] nums, int min, int max)
	{
		int bound = max - min + 1;
		Random random = new Random();
		for (int i = 0; i < nums.length; i++) {
			nums[i] = min + random.nextInt(bound);
		}
	}

	public static void randomNumbers(BigInteger[] nums, BigInteger min, BigInteger max)
	{
		BigInteger bound = max.subtract(min).add(BigInteger.ONE);
		int numBits = bound.bitLength();
		Random random = new Random();
		for (int i = 0; i < nums.length; ) {
			BigInteger num = min.add(new BigInteger(numBits, random));
			if (num.compareTo(max) > 0)
				continue;
			nums[i++] = num;
		}
	}

	public static void randomNumbers(BigInteger[] nums, int numBits)
	{
		Random random = new Random();
		for (int i = 0; i < nums.length; i++) {
			nums[i] = new BigInteger(numBits, random);
		}
	}

}

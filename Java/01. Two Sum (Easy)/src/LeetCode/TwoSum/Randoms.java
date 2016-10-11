/**
 * 
 */
package LeetCode.TwoSum;

import LeetCode.RandomSamples;

/**
 * @author Roman
 *
 */
public class Randoms extends RandomSamples<Sample>
{
	int[] randomLength;
	int maxLength;

	public Randoms(int maxLength) {
		this.maxLength = maxLength;
	}

	//@Override
	public Sample[] prepareSet(Sample[] samples, int nSamples, int N)
	{
		samples = super.prepareSet(samples, nSamples, N);
		nSamples = this.nSamples;
		N = this.N;
		
		if (N <= 1) {
			randomLength = new int[nSamples];
			randomNumbers(randomLength, 2, maxLength);
		}
		
		for (int i = 0; i < nSamples; i++)
		{
			int length = N > 1 ? N : randomLength[i];

			int[] nums = new int[length];
			randomNumbers(nums, 0, Integer.MAX_VALUE / 2);

			int[] ind = new int[2];
			do {
				randomNumbers(ind, 0, length-1);
			} while (ind[0] == ind[1]);
			
			int target = nums[ind[0]] + nums[ind[1]];
			
			samples[i] = new Sample(nums, target, ind);
		}
		
		return samples;
	}
};

/**
 * 
 */
package LeetCode.MedianOfTwoSortedArrays;

import java.util.Arrays;
import java.util.function.BiFunction;

import LeetCode.RandomSamples;

/**
 * @author Roman
 *
 */
public class Randoms extends RandomSamples<Sample>
{
	int maxLength;
	BiFunction<int[], int[], Double> getResult;

	public Randoms(int maxLength,  BiFunction<int[], int[], Double> getResult)
	{
		this.maxLength = maxLength;
		this.getResult = getResult;
	}

	//@Override
	public Sample[] prepareSet(Sample[] samples, int nSamples, int N)
	{
		samples = super.prepareSet(samples, nSamples, N);
		nSamples = this.nSamples;
		N = this.N;

		int[] randomLength = null;
		if (N == 0) {
			randomLength = new int[2*nSamples];
			randomNumbers(randomLength, 2, maxLength);
		}
		
		for (int i = 0, k = 0; i < nSamples; i++)
		{
			int length1, length2;
			if (N > 0) {
				length1 = length2 = N;
			} else {
				length1 = randomLength[k++];
				length2 = randomLength[k++];
			}

			int[] nums1 = new int[length1];
			int[] nums2 = new int[length2];
			randomNumbers(nums1, 1, Integer.MAX_VALUE);
			randomNumbers(nums2, 1, Integer.MAX_VALUE);
			Arrays.sort(nums1);
			Arrays.sort(nums2);
			
			double result = getResult.apply(nums1, nums2);
			samples[i] = new Sample(nums1, nums2, result);
		}
		
		return samples;
	}
}

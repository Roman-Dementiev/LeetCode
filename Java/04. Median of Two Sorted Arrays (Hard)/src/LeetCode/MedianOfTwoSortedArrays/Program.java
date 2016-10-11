/**
 * 
 */
package LeetCode.MedianOfTwoSortedArrays;

import java.util.function.BiFunction;

import LeetCode.*;

/**
 * @author Roman
 *
 */
public class Program extends TestProgram<Sample>
{
	Sample[] samples = {
			new Sample(new int[]{ 100000}, new int[]{100001}, 100000.5),
			new Sample(new int[]{ 1, 3 }, new int[]{ 2 }, 2),
			new Sample(new int[]{ 1, 2 }, new int[]{ 3, 4 }, 2.5),
			new Sample(new int[]{ 1, 2 }, new int[]{ 1, 2, 3 }, 2),
			new Sample(new int[]{ 1, 2, 3 }, new int[]{ 1, 2 }, 2),
			new Sample(new int[]{ 1 }, new int[]{ 2, 3, 4 }, 2.5),
			new Sample(new int[]{ 1, 1, 1 }, new int[]{ 1, 1, 1 }, 1),
			new Sample(new int[]{ 2, 3, 4, 5, 6 }, new int[]{ 1 }, 3.5),
			new Sample(new int[]{ 1, 2 }, new int[]{ }, 1.5),
			new Sample(new int[]{ 2 }, new int[]{ 1, 3, 4 }, 2.5),
			new Sample(new int[]{ 3 }, new int[]{ 1, 2, 4 }, 2.5),
			new Sample(new int[]{ 5 }, new int[]{ 1, 2, 3, 4, 6 }, 3.5),
			new Sample(new int[]{ }, new int[]{ 3, 4 }, 3.5),
		};

	public static void main(String[] args)
	{
		Program program = new Program();
		program.run();
	}

	public void run()
	{
		Solution0 verify = new Solution0();
		Solution2 sol = new Solution2();

		setTest(sample -> {
			double result = sol.findMedianSortedArrays(sample.arg1(), sample.arg2());
			sample.setResult(result);
		});
	
		
		runTests(samples);
		
		BiFunction<int[], int[], Double> getResult = (nums1, nums2) -> {
			return verify.findMedianSortedArrays(nums1, nums2);
		};
		
		Randoms randoms = new Randoms(100, getResult);
		randomTests(randoms, new Sample[100000]);
		randomTests(randoms, new Sample[10000], 100, 1000, 100);

		printSummary(true);
	}
};


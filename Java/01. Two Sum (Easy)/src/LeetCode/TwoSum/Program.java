/**
 * 
 */
package LeetCode.TwoSum;

import LeetCode.*;

/**
 * @author Roman Dementiev
 *
 */
public class Program extends TestProgram<Sample>
{
	Sample[] samples = {
		new Sample(new int[] { 2, 7, 11, 15 }, 9, new int[] {0, 1}),
		new Sample(new int[] { 3, 2, 4 }, 6, new int[] {1, 2}),
		new Sample(new int[] {
			230, 863, 916, 585, 981, 404, 316, 785, 88, 12, 70, 435, 384,
			778, 887, 755, 740, 337, 86, 92, 325, 422, 815, 650, 920, 125,
			277, 336, 221, 847, 168, 23, 677, 61, 400, 136, 874, 363, 394,
			199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422,
			927, 783, 930, 282, 306, 506, 44, 926, 691, 568, 68, 730, 933,
			737, 531, 180, 414, 751, 28, 546, 60, 371, 493, 370, 527, 387,
			43, 541, 13, 457, 328, 227, 652, 365, 430, 803, 59, 858, 538,
			427, 583, 368, 375, 173, 809, 896, 370, 789 },
			542, new int[] { 28,45 }),
		new Sample(null, 0, null)
	};
	
	public void run()
	{
		Solution2 sol = new Solution2();

		setTest(sample -> {
			int[] result = sol.twoSum(sample.arg1(), sample.arg2());
			sample.setResult(result);
		});
		
		runTests(samples);
		
		Randoms randoms = new Randoms(100);
		randomTests(randoms, new Sample[1000], 0);
		randomTests(randoms, new Sample[100], 100, 2000, 100);

		printSummary(true);
	}
	
	public static void main(String[] args)
	{
		Program program = new Program();
		program.run();
	}
}

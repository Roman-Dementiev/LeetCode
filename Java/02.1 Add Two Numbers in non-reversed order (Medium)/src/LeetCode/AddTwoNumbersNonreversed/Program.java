/**
 * 
 */
package LeetCode.AddTwoNumbersNonreversed;

import LeetCode.*;

/**
 * @author Roman
 *
 */
public class Program extends TestProgram<Sample>
{
	Sample[] samples = {
			new Sample("1", "1"),
			new Sample("342", "465"),
			new Sample("991", "9"),
			new Sample("242", ""),
			new Sample(null, "465"),
			new Sample(null, null, null)
		};
		
	public void run()
	{
		Solution sol = new Solution();

		setTest(sample -> {
			ListNode result = sol.addTwoNumbers(sample.arg1().head(), sample.arg2().head());
			sample.setResult(new DigitList(result));
		});
			
		runTests(samples);
			
		Randoms randoms = new Randoms();
		randomTests(randoms, new Sample[100000]);
		randomTests(randoms, new Sample[10000], 10, 200, 10);

		printSummary(true);
			
	}
		
	public static void main(String[] args)
	{
		Program program = new Program();
		program.run();
	}
}

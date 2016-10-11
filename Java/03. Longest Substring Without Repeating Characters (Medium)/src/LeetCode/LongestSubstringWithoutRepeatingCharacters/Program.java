/**
 * 
 */
package LeetCode.LongestSubstringWithoutRepeatingCharacters;

import LeetCode.*;

/**
 * @author Roman Dementiev
 *
 */
public class Program extends TestProgram<Sample>
{
	Sample[] samples = {
			new Sample("pwwkew", 3),
			new Sample("abcabcbb", 3),
			new Sample("bbbbb", 1),
			new Sample("", 0)
		};
		
	public void run()
	{
		Solution0 verify = new Solution0();
		Solution2 sol = new Solution2();

		setTest(sample -> {
			int result = sol.lengthOfLongestSubstring(sample.arg1());
			sample.setResult(result);
		});
		
		runTests(samples);
		
		Randoms randoms = new Randoms(100, str -> verify.lengthOfLongestSubstring(str));
		randomTests(randoms, new Sample[10000]);
		randomTests(randoms, new Sample[1000], 100, 1000, 100);

		printSummary(true);
			
	}
		
	public static void main(String[] args)
	{
		Program program = new Program();
		program.run();
	}

}

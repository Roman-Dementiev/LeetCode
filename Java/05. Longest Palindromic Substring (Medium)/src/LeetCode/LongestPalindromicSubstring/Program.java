/**
 * 
 */
package LeetCode.LongestPalindromicSubstring;

import LeetCode.TestProgram;

/**
 * @author Roman Dementiev
 *
 */
public class Program extends TestProgram<Sample>
{
	Sample[] samples = new Sample[] {
		new Sample("", ""),
		new Sample("a", "a"),
		new Sample("ab", "a"),
		new Sample("aba", "aba"),
		new Sample("abab", "aba"),
		new Sample("abba", "abba"),
		new Sample("aaaa", "aaaa")
	};


	public static void main(String[] args)
	{
		Program program = new Program();
		program.run();
	}

	public void run()
	{
		Solution0 verify = new Solution0();
		Solution1 sol = new Solution1();

		setTest(sample -> {
			String result = sol.longestPalindrome(sample.arg1());
			sample.setResult(result);
		});
		
		runTests(samples);
		
		Randoms randoms = new Randoms(1000, str -> verify.longestPalindrome(str));
		randomTests(randoms, new Sample[10000]);
		randomTests(randoms, new Sample[1000], 100, 1000, 100);

		printSummary(true);
	}
}

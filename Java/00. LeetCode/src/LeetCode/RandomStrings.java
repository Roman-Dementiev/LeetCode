/**
 * 
 */
package LeetCode;

/**
 * @author Roman
 *
 */
public abstract class RandomStrings<TSample> extends RandomSamples<TSample>
{
	protected int maxLength;
	protected String[] strings;

	public RandomStrings(int maxLength)
	{
		this.maxLength = maxLength;
	}

	//@Override
	public TSample[] prepareSet(TSample[] samples, int nSamples, int N)
	{
		samples = super.prepareSet(samples, nSamples, N);
		nSamples = this.nSamples;
		N = this.N;

		strings = new String[nSamples];
		if (N == 0) {
			randomStrings(strings, maxLength, false);
		} else {
			randomStrings(strings, N, true);
		}
		
		return samples;
	}

	public static void randomStrings(String[] strings, int maxLength, boolean fixedLength, String chars)
	{
		int[] randomlength = null;
		if (!fixedLength) {
			randomlength = new int[strings.length];
			randomNumbers(randomlength, 0, maxLength);
		}
		
		int charsCount = chars.length();
		for (int i = 0; i < strings.length; i++) {
			int len = fixedLength ? maxLength : randomlength[i];
			int[] randomInd = new int[len];
			randomNumbers(randomInd, 0, charsCount-1);
			StringBuilder sb = new StringBuilder();
			for (int k = 0; k < len; k++) {
				int ind = randomInd[k];
				sb.append(chars.charAt(ind));
			}
			strings[i] = sb.toString();
		}
	}

	public static void randomStrings(String[] strings, int maxLength, boolean fixedLength)
	{
		randomStrings(strings, maxLength, fixedLength, cLetters);
	}
	
	static String cLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZ";
}

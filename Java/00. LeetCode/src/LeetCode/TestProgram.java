/**
 * 
 */
package LeetCode;

import java.util.function.Consumer;
import java.util.function.Function;
import java.io.PrintStream;


/**
 * @author Roman Dementiev
 *
 */

public abstract class TestProgram<TSample extends TestSample<?,?,?,?>>
{
	protected PrintStream out;
	protected Consumer<TSample> test = null;
	protected Function<TSample, TestStatus> verify = null;
	protected long setTime = 0, sumTime = 0;
	protected int setTests = 0, setPassed = 0, setFailed = 0;
	protected int sumTests = 0, sumPassed = 0, sumFailed = 0;
	protected boolean needEOL = false;
	
	
	public TestProgram()
	{
		this(System.out);
	}
	
	public TestProgram(PrintStream out)
	{
		this.out = out;
	}
	
	public void reset(boolean resetSummary)
	{
		setTime = setTests = setPassed = setFailed = 0;
		if (resetSummary) {
			sumTime = sumTests = sumPassed = sumFailed = 0;
		}
	}
	
	public void setTest(Consumer<TSample> test)
	{
		this.test = test;
	}
	
	public void setVerify(Function<TSample, TestStatus> verify)
	{
		this.verify = verify;
	}
	
	protected void test(TSample sample, boolean printSample, boolean printFailed)
	{
		// TODO: Timing
		long start = System.nanoTime();
		test.accept(sample);
		long end = System.nanoTime();
		long time = end - start;

		setTests++;
		sumTests++;
		setTime += time;
		sumTime += time;
		
		TestStatus status;
		if (verify != null) {
			status = verify.apply(sample);
		} else {
			status = sample.verify();
		}
		sample.setStatus(status);
		
		if (status == TestStatus.Passed) {
			setPassed++;
			sumPassed++;
		} else if (status == TestStatus.Failed)  {
			setFailed++;
			sumFailed++;
			if (printFailed)
				printSample = true;
		}

		if (printSample && out != null) {
			out.println(sample.toString());
		}
	}

	public void runTests(TSample[] samples)
	{
		runTests(samples, true, true);
	}
	
	public void runTests(TSample[] samples, boolean printSample, boolean printFailed)
	{
		reset(false);
		for (TSample sample : samples) {
			if (sample == null)
				break;
			test(sample, printSample, printFailed);
		}
	}	

	public void randomTests(RandomSamples<TSample> randoms, TSample[] samples)
	{
		randomTests(randoms, samples, 0);
	}
	
	public void randomTests(RandomSamples<TSample> randoms, TSample[] samples, int N)
	{
		if (out != null) {
			out.print("Random tests");
			if (N > 0) {
				out.format(" for N=%d:", N);
			} else {
				out.print(" for random N:");
			}
			out.flush();
			needEOL = true;
		}

		samples = randoms.prepareSet(samples, samples.length, N);
		runTests(samples, false, true);

		if (out != null) {
			long ms = setTime / 1000000;
			out.format(" %dms", ms);
			if (setPassed > 0 || setFailed > 0) {
				out.format(", %d passed, %d failed", setPassed, setFailed);
			}
			out.println("");
			needEOL = false;
		}
	}

	public void randomTests(RandomSamples<TSample> randoms, TSample[] samples, int minN, int maxN, int stepN, int multN)
	{
		if (maxN < minN)
			maxN = minN;

		if (multN <= 1) {
			multN = 1;
			if (stepN < 1)
				stepN = 1;
		}
	
		for (int N = minN; N <= maxN; N = N * multN + stepN)
		{
			randomTests(randoms, samples, N);
		}
	}

	public void randomTests(RandomSamples<TSample> randoms, TSample[] samples, int minN, int maxN, int stepN)
	{
		randomTests(randoms, samples, minN, maxN, stepN, 1);
	}
	
	public void randomTests(RandomSamples<TSample> randoms, TSample[] samples, int minN, int maxN)
	{
		randomTests(randoms, samples, minN, maxN, 1, 1);
	}
	
	public void printSample(TSample sample)
	{
		if (out == null)
			return;
		
		newline();
		out.println(sample.toString());
	}
	
	public void printSummary(boolean reset)
	{
		if (out != null) {
			newline();
			out.print("Total ");
			out.print(sumTests);
			out.print(" tests, ");
			out.print(sumPassed);
			out.print(" passed, ");
			out.print(sumFailed);
			out.println(" failed.");
		}
		if (reset) {
			reset(true);
		}
	}

	protected void newline()
	{
		if (needEOL) {
			out.println("");
			needEOL = false;
		}
	}
};

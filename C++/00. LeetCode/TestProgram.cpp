#include "TestProgram.h"
#include "Printout.h"

namespace LeetCode
{
	TestProgramBase::TestProgramBase(ostream* out, PrintoutMode mode) :
		out(out), mode(mode), needEOL(false)
	{
		Reset();
	}

	void TestProgramBase::SetOutput(ostream* out, PrintoutMode mode)
	{
		this->out = out;
		this->mode = mode;
	}

	void TestProgramBase::PrintSummary(bool reset)
	{
		if (out != nullptr) {
			Newline();
			*out << "Total " << sumTests << " tests, " << sumPassed << " passed, " << sumFailed << " failed." << endl;
		}
		if (reset) {
			Reset();
		}
	}

	void TestProgramBase::Reset()
	{
		setTests = setPassed = setFailed = 
		sumTests = sumPassed = sumFailed = 0;
		setTime = sumTime = duration_t::zero();
	}

	void TestProgramBase::Newline()
	{
		if (needEOL) {
			*out << endl;
			needEOL = false;
		}
	}

	void TestProgramBase::Backspace(int count)
	{
		if (needEOL) {
			for (int i = 0; i < count; i++) {
				*out << '\b';
			}
			for (int i = 0; i < count; i++) {
				*out << ' ';
			}
			for (int i = 0; i < count; i++) {
				*out << '\b';
			}
		}
	}


	template<class TSample, typename TResult>
	TestProgram<TSample, TResult>::TestProgram(ostream* out, PrintoutMode mode, Test_t test, Verify_t verify) :
		TestProgramBase(out, mode),
		test(test), verify(verify)
	{
	}

	template<class TSample, typename TResult>
	void TestProgram<TSample, TResult>::Test(Sample_t& sample, bool printSample, bool printFailed)
	{
		clock_t::time_point start = clock_t::now();
		test(sample);
		clock_t::time_point end = clock_t::now();
		duration_t time = end - start;

		setTests++;
		sumTests++;
		setTime += time;
		sumTime += time;

		bool success, unknown = false;
		if (verify != nullptr) {
			success = verify(sample);
		} else if (sample.Expected() != nullptr) {
			success = (*sample.Result() == *sample.Expected());
		} else {
			unknown = true;
		}

		if (unknown) {
			sample.SetStatus(TestStatus::Unknown);
		}
		else if (success) {
			sample.SetStatus(TestStatus::Passed);
			setPassed++;
			sumPassed++;
		} else {
			sample.SetStatus(TestStatus::Failed);
			setFailed++;
			sumFailed++;
			if (printFailed)
				printSample = true;
		}

		if (printSample) {
			PrintSample(sample);
		}
	}

	template<class TSample, typename TResult>
	void TestProgram<TSample, TResult>::RunTests(vector<Sample_t>& samples, bool printSamples, bool printFailed)
	{
		setTests = setPassed = setFailed = 0;
		setTime = duration_t::zero();

		for (auto it = samples.begin(); it != samples.end(); it++)
		{
			Sample_t& sample = *it;
			Test(sample, printSamples, printFailed);
		}
	}

	template<class TSample, typename TResult>
	void TestProgram<TSample, TResult>::RunTests(Samples_t& samples, bool printSamples, bool printFailed)
	{
		setTests = setPassed = setFailed = 0;
		setTime = duration_t::zero();

		for (auto it = samples.begin(); it != samples.end(); it++)
		{
			Sample_t* sample = *it;
			if (sample == nullptr)
				break;
 
			Test(*sample, printSamples, printFailed);
		}
	}

	template<class TSample, typename TResult>
	void TestProgram<TSample, TResult>::RandomTests(Random_t& random, int nSamples, int N)
	{
		if (out != nullptr) {
			*out << "Random tests";
			if (N > 0) {
				*out << " for N=" << N;
			}
			*out << ": Generating...";
			needEOL = true;
		}

		random.PrepareSet(nSamples, N);
		nSamples = random.NumSamples();
		N = random.N();

		Samples_t samples(nSamples);
		for (int i = 0; i < nSamples; i++)
		{
			Sample_t* sample = random.GetSample();
			if (sample == nullptr)
				break;

			samples[i] = sample;
		}


		if (out != nullptr) {
			Backspace(13);
			*out << "Running...";
		}
		RunTests(samples, false);

		if (out != nullptr) {
			chrono::milliseconds ms = chrono:: duration_cast<chrono::milliseconds>(setTime);
			Backspace(10);
			*out << ms.count() << "ms";
			if (setPassed > 0 || setFailed > 0) {
				*out << ", " << setPassed << " passed " << setFailed << " failed";
			}
			*out << endl;
			needEOL = false;
		}
	}

	template<class TSample, typename TResult>
	void TestProgram<TSample, TResult>::RandomTests(Random_t& random, int nSamples, int minN, int maxN, int stepN, int multN)
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
			RandomTests(random, nSamples, N);
		}
	}


	template<class TSample, typename TResult>
	void TestProgram<TSample, TResult>::PrintSample(const Sample_t& sample)
	{
		if (out == nullptr)
			return;

		Newline();

		const TSample::Args_t& args = sample.Args();
		*out <<  Printout<TSample::Args_t>(args, mode);;
		needEOL = true;

		if (sample.Result() != nullptr) {
			*out << " => " << Printout<TResult>(*sample.Result(), mode);
			needEOL = true;
		}
		if (sample.Status() == TestStatus::Passed) {
			*out << "  Passed";
			needEOL = true;
		}
		else if (sample.Status() == TestStatus::Failed) {
			*out << "  Failed";
			if (sample.Expected() != nullptr) {
				*out << ", expected " << Printout<TResult>(*sample.Expected(), mode);
			}
			needEOL = true;
		}

		Newline();
	}


#define TEST_TYPE1(TResult, TArg1)\
	template class TestProgram<TestSample<TResult, TArg1>, TResult>;

#define TEST_TYPE2(TResult, TArg1, TArg2)\
	template class TestProgram<TestSample<TResult, TArg1, TArg2>, TResult>;

#define TEST_TYPE3(TResult, TArg1, TArg2, TArg3)\
	template class TestProgram<TestSample<TResult, TArg1, TArg2, TArg3>, TResult>;

#include "TestTypes.h"

} //namespace LeetCode

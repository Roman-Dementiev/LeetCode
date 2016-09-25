#pragma once
#pragma once
#include "LeetCode.h"
#include <iostream>
#include <chrono>

using namespace std;

namespace LeetCode
{
	enum class Void;
	enum class TestStatus;
	template<typename TResult, typename... Args> class TestSample;
	template<class TSample> class TestSamples;
	template<class TSample> class RandomSamples;
	template<typename T> class Printout;
	enum class PrintoutMode;

//	typedef std::chrono::steady_clock clock_t;
	typedef std::chrono::high_resolution_clock clock_t;
	typedef clock_t::duration duration_t;


	enum class PrintoutMode {
		Default,
		Uniform,
		Json
	};

	class TestProgramBase
	{
	public:
		TestProgramBase(ostream* out, PrintoutMode mode = PrintoutMode::Default);
		void SetOutput(ostream* out, PrintoutMode mode = PrintoutMode::Default);
		void PrintSummary(bool reset = true);
		void Reset();

	protected:
		void Newline();
		void Backspace(int count=1);

	protected:
		ostream* out;
		PrintoutMode mode;
		
		int setTests, setPassed, setFailed;
		int sumTests, sumPassed, sumFailed;
		duration_t setTime, sumTime;
		bool needEOL;

	};


	template<class TSample, typename TResult>
	class TestProgram : public TestProgramBase
	{
	public:
		typedef TSample Sample_t;
		typedef TResult Result_t;
		typedef TestSamples<TSample> Samples_t;
		typedef RandomSamples<TSample> Random_t;
		typedef function <void(TSample&)> Test_t;
		typedef function <bool(TSample&)> Verify_t;

		TestProgram(ostream* out, PrintoutMode mode = PrintoutMode::Default, Test_t test = nullptr, Verify_t verify = nullptr);
		TestProgram(ostream& out = cout, PrintoutMode mode = PrintoutMode::Default, Test_t test = nullptr, Verify_t verify = nullptr) :
			TestProgram(&out, mode, test, verify)
		{}

		void SetTest(Test_t test) { this->test = test; }
		void SetVerify(Verify_t verify) { this->verify = verify; }

		void Test(Sample_t& sample, bool printSample = true, bool printFailed = true);
		void RunTests(vector<Sample_t>& samples, bool printSamples = true, bool printFailed = true);
		void RunTests(Samples_t& samples, bool printSamples = true, bool printFailed = true);
		void RandomTests(Random_t& random, int nSamples, int N = 0);
		void RandomTests(Random_t& random, int nSamples, int minN, int maxN, int stepN = 1, int multN = 1);
	
		void PrintSample(const Sample_t& sample);

	protected:
		Test_t test;
		Verify_t verify;
	};
}

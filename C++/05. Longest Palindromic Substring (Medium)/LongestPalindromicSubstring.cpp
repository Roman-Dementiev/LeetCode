#include "stdafx.h"
#include "Solution0.h"
#include "Solution1.h"
#include "Solution2.h"

#undef Solution
#define Solution Solution2
#define VerifySol Solution0

using TestSample = LeetCode::TestSample<string, string>;
using TestResult = TestSample::Result_t;
using TestSamples = LeetCode::TestSamples<TestSample>;
using TestProgram = LeetCode::TestProgram<TestSample, TestResult>;


class RandomSamples : public LeetCode::RandomStringSamples<TestSample>
{
	VerifySol verify;
	vector<string> strings;
public:
	RandomSamples(int maxLength) : RandomStringSamples(maxLength) {}

	virtual TestSample* GetSample(string&& str) override
	{
		string result = verify.longestPalindrome(str);
		return new TestSample(forward<string>(str), move(result));
	}
};


class LongestPalindromicSubstring : TestProgram
{
public:
	void Run()
	{
		TestSamples samples = {
			new TestSample("", ""),
			new TestSample("a", "a"),
			new TestSample("ab", "a"),
			new TestSample("aba", "aba"),
			new TestSample("abab", "aba"),
			new TestSample("abba", "abba"),
			new TestSample("aaaa", "aaaa")
		};

		Solution sol;
		auto test = [&sol](TestSample& sample) {
			string str = sample.Arg<0>();
			string result = sol.longestPalindrome(str);
			sample.SetResult(forward<string>(result));
		};

		auto verify = [this](TestSample& sample) {
			return Verify(sample.Result(), sample.Expected());
		};

		SetTest(test);
		SetVerify(verify);
		RunTests(samples);

		RandomSamples random(200);
		RandomTests(random, 1000);
		RandomTests(random, 100, 50, 500, 50);

		PrintSummary();
	}

	bool Verify(string* result, string* expected)
	{
		if (result == nullptr)
			return false;

		if (expected != nullptr) {
			if (result->length() < expected->length())
				return false;

			if (*result == *expected)
				return true;
		}

		for (int i = 0, j = result->length() - 1; i < j; i++, j--) {
			if (result->at(i) != result->at(j))
				return false;
		}

		return true;
	}
};

int main()
{
	LongestPalindromicSubstring program;
	program.Run();
	return 0;
}


#include "stdafx.h"
#include "LeetCode.h"
#include "Solution0.h"
#include "Solution1.h"
#include "Solution2.h"

#undef Solution
#define Solution Solution1
#define VerifySol Solution2

using TestSample = LeetCode::TestSample<int, string>;
using TestSamples = LeetCode::TestSamples<TestSample>;
using TestProgram = LeetCode::TestProgram<TestSample, int>;


class RandomSamples : public LeetCode::RandomSamples<TestSample>
{
	int maxLength;
	vector<string> strings;
#ifdef VerifySol
	VerifySol verifySol;
#endif
public:
	RandomSamples(int maxLength) : maxLength(maxLength) {}

	virtual void PrepareSet(int nSamples = defaultSetSize, int N = 0) override
	{
		LeetCode::RandomSamples<TestSample>::PrepareSet(nSamples, N);
		nSamples = this->nSamples;
		N = _N;

		if (N == 0) {
			LeetCode::RandomStrings(strings, nSamples, maxLength, false);
		} else {
			LeetCode::RandomStrings(strings, nSamples, N, true);
		}
	}

	virtual TestSample* GetSample() override
	{
		if (nSamples == 0) {
			PrepareSet();
		}
		if (current == strings.size())
			current = 0;

		string str = strings[current++];
#ifdef VerifySol
		int result = verifySol.lengthOfLongestSubstring(str);
		return new TestSample(move(str), move(result));
#else
		return new TestSample(move(str));
#endif
	}
};


class LongestSubstringWithoutRepeatingCharacters : TestProgram
{
public:
	void Run()
	{
		TestSamples samples = {
				new TestSample("pwwkew", 3),
				new TestSample("abcabcbb", 3),
				new TestSample("bbbbb", 1),
				new TestSample("", 0)
			};

		Solution sol;
		auto test = [&sol](TestSample& sample) {
			string str = sample.Arg<0>();
			int result = sol.lengthOfLongestSubstring(str);
			sample.SetResult(move(result));
		};

		SetTest(test);
		RunTests(samples);

		RandomSamples random(100);
		RandomTests(random, 1000);
		RandomTests(random, 100, 10, 200, 10);

		PrintSummary();
	}
};

int main()
{
	LongestSubstringWithoutRepeatingCharacters program;
	program.Run();
	return 0;
}


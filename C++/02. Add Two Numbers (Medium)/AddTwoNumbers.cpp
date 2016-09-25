#include "stdafx.h"
#include "LeetCode.h"
#include "Solution.h"

using ListNode = LeetCode::ListNode<int>;
using List = LeetCode::List<int>;
using TestSample = LeetCode::TestSample<LeetCode::List<int>, LeetCode::List<int>, LeetCode::List<int>>;
using TestSamples = LeetCode::TestSamples<TestSample>;
using TestProgram = LeetCode::TestProgram<TestSample, List>;


void IntToList(unsigned long long num, List &list)
{
	do {
		list >> num % 10;
		num /= 10;
	} while (num > 0);
}

class RandomSamples : public LeetCode::RandomSamples<TestSample>
{
	vector<unsigned long long> randomNums;
public:
	virtual void PrepareSet(int nSamples = defaultSetSize, int N = 0) override
	{
		LeetCode::RandomSamples<TestSample>::PrepareSet(nSamples, N);
		nSamples = this->nSamples;
		N = _N;
		
		unsigned long long min = 1, max;
		if (N <= 0) {
			max = ULLONG_MAX / 2;
		} else {
			while (min < _N) {
				min *= 10;
			}
			max = min * 10 - 1;
		}
		LeetCode::UniformIntNumbers(randomNums, 2*nSamples, min, max);
	}

	virtual TestSample* GetSample() override
	{
		if (nSamples <= 0) {
			PrepareSet();
		}
		if (current >= randomNums.size()-1)
			current = 0;
		unsigned long long n1 = randomNums[current++];
		unsigned long long n2 = randomNums[current++];

		List l1, l2, lr;
		IntToList(n1, l1);
		IntToList(n2, l2);
		IntToList(n1+n2, lr);
		return new TestSample(move(l1), move(l2), move(lr));
	}
};

class AddTwoNumbers : TestProgram
{
public:
	void Run()
	{
		TestSamples samples = {
			new TestSample({2, 4, 6}, {5, 6, 4}, {7, 0, 1, 1}),
			new TestSample({1, 9, 9, 9}, {9}, {0, 0, 0, 0, 1}),
			new TestSample({2, 4, 6}, {}, {2, 4, 6}),
			new TestSample({}, {5, 6, 4}, {5, 6, 4}),
			new TestSample({}, {}, {}),
			nullptr
		};


		Solution sol;
		auto test = [&sol](TestSample& sample) {
			List& l1 = sample.Arg<0>();
			List& l2 = sample.Arg<1>();
			List result = sol.addTwoNumbers(l1 .Head(), l2.Head());
			sample.SetResult(move(result));
		};

		SetTest(test);
		SetVerify(verify);
		RunTests(samples);

		RandomSamples random;
		RandomTests(random, 100000);
		RandomTests(random, 10000, 1, 22);

		PrintSummary();
	}
};

int main()
{
	AddTwoNumbers program;
	program.Run();
	return 0;
}


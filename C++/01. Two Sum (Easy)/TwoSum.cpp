#include "stdafx.h"
#include "LeetCode.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Printout.h"

using TestSample = LeetCode::TestSample<vector<int>, vector<int>, int>;
using TestResult = TestSample::Result_t;
using TestSamples = LeetCode::TestSamples<TestSample>;
using TestProgram = LeetCode::TestProgram<TestSample, TestResult>;


class RandomSamples : public LeetCode::RandomSamples<TestSample>
{
	vector<int> randomLength;
	int maxLength;
public:
	RandomSamples(int maxLength) : maxLength(maxLength) {}

	virtual void PrepareSet(int nSamples = defaultSetSize, int N = 0) override
	{
		LeetCode::RandomSamples<TestSample>::PrepareSet(nSamples, N);
		nSamples = this->nSamples;
		N = _N;
		
		if (N <= 0) {
			LeetCode::UniformIntNumbers(randomLength, nSamples, 2, maxLength);
		}
	}

	virtual TestSample* GetSample() override
	{
		if (nSamples <= 0) {
			PrepareSet();
		}

		if (current >= nSamples)
			current = 0;
		int length = _N > 1 ? _N : randomLength[current++];

		vector<int> nums, ind;
		LeetCode::UniformIntNumbers(nums, length, 0, INT_MAX / 2);
		LeetCode::UniformIntNumbers(ind, 2, 0, length-1);
		int target = nums[ind[0]] + nums[ind[1]];
		return new TestSample(move(nums), move(target));
	}
};

class TwoSum : TestProgram
{
public:
	void Run()
	{
		TestSamples samples = {
			new TestSample({ 2, 7, 11, 15 }, 9, {0, 1}),
			new TestSample({ 3, 2, 4 }, 6, {1, 2}),
			new TestSample({
				230, 863, 916, 585, 981, 404, 316, 785, 88, 12, 70, 435, 384,
				778, 887, 755, 740, 337, 86, 92, 325, 422, 815, 650, 920, 125,
				277, 336, 221, 847, 168, 23, 677, 61, 400, 136, 874, 363, 394,
				199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422,
				927, 783, 930, 282, 306, 506, 44, 926, 691, 568, 68, 730, 933,
				737, 531, 180, 414, 751, 28, 546, 60, 371, 493, 370, 527, 387,
				43, 541, 13, 457, 328, 227, 652, 365, 430, 803, 59, 858, 538,
				427, 583, 368, 375, 173, 809, 896, 370, 789
				},
				542, { 28,45 }),
			new TestSample({}, 0),
			nullptr
		};

		Solution sol;
		auto test = [&sol](TestSample& sample) {
			TestResult result = sol.twoSum(sample.Arg<0>(), sample.Arg<1>());
			sample.SetResult(move(result));
		};
		auto verify = [this](TestSample& sample) {
			return Verify(sample);
		};

		SetTest(test);
		SetVerify(verify);
		RunTests(samples);

		RandomSamples random(100);
		RandomTests(random, 1000);
		RandomTests(random, 100, 100, 2000, 100);

		PrintSummary();
	}

	bool Verify(TestSample &sample)
	{
		TestResult* result = sample. Result();
		TestResult* expected = sample.Expected();

		if (result == nullptr) {
			return false;
		}
		if (result->size() == 0) {
			return expected == nullptr || expected->size() == 0;
		}
		if (result->size() != 2) {
			return false;
		}

		int i1 = (*result)[0];
		int i2 = (*result)[1];
		int n1 = sample.Arg<0>()[i1];
		int n2 = sample.Arg<0>()[i2];
		int sum = sample.Arg<1>();

		return n1 + n2 == sum;
	}
};

int main()
{
	TwoSum program;
	program.Run();
	return 0;
}


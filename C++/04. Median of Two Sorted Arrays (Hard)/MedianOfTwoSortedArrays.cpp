#include "stdafx.h"
#include "LeetCode.h"
#include "Solution1.h"
#include "Solution2.h"
#include <algorithm>
#include <climits>

using TestSample = LeetCode::TestSample<double, vector<int>, vector<int>>;
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

		LeetCode::UniformIntNumbers(randomLength, nSamples, 2, maxLength);
	}

	virtual TestSample* GetSample() override
	{
		int length1, length2;
		if (_N > 0) {
			length1 = length2 = _N;
		} else {
			if (current >= randomLength.size())
				current = 0;
			length1 = randomLength[current++];
			length2 = randomLength[current++];
		}

		vector<int> nums1, nums2;
		LeetCode::UniformIntNumbers(nums1, length1, 1, INT_MAX);
		LeetCode::UniformIntNumbers(nums2, length2, 1, INT_MAX);
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		
		vector<int> merged(length1+length2);
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
		double median = Solution::FindMedianSortedArray(merged);

		return new TestSample(move(nums1), move(nums2), move(median));
	}
};


class MedianOfTwoSortedArrays : TestProgram
{
public:
	void Run()
	{
		TestSamples samples = {
			new TestSample({ 100000}, {100001}, 100000.5),
			new TestSample({ 1, 3 }, { 2 }, 2),
			new TestSample({ 1, 2 }, { 3, 4 }, 2.5),
			new TestSample({ 1, 2 }, { 1, 2, 3 }, 2),
			new TestSample({ 1, 2, 3 }, { 1, 2 }, 2),
			new TestSample({ 1 }, { 2, 3, 4 }, 2.5),
			new TestSample({ 1, 1, 1 }, { 1, 1, 1 }, 1),
			new TestSample({ 2, 3, 4, 5, 6 }, { 1 }, 3.5),
			new TestSample({ 1, 2 }, { }, 1.5),
			new TestSample({ 2 }, { 1, 3, 4 }, 2.5),
			new TestSample({ 3 }, { 1, 2, 4 }, 2.5),
			new TestSample({ 5 }, { 1, 2, 3, 4, 6 }, 3.5),
			new TestSample({ }, { 3, 4 }, 3.5),
		};

		Solution sol;
		auto test = [&sol](TestSample& sample) {
			vector<int>& nums1 = sample.Arg<0>();
			vector<int>& nums2 = sample.Arg<1>();
			double result = sol.findMedianSortedArrays(nums1, nums2);
			sample.SetResult(forward<double>(result));
		};

		SetTest(test);
		RunTests(samples);

		RandomSamples random(100);
		RandomTests(random, 1000);

		PrintSummary();
	}
};

int main()
{
	MedianOfTwoSortedArrays program;
	program.Run();
	return 0;
}


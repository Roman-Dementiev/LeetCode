#pragma once
#include "LeetCode.h"

namespace LeetCode
{
	template<class TSample> class TestSamples;

	template<class TSample>
	class RandomSamples
	{
		RandomSamples(const RandomSamples&) = delete;
		RandomSamples& operator=(const RandomSamples&) = delete;
	public:
		typedef TSample TestSample;
		static const int defaultSetSize = 1000;

		RandomSamples() : _N(0), nSamples(0), current(0) {}
		virtual ~RandomSamples() = default;

		int N() const { return _N; }
		int NumSamples() const {
			return nSamples;
		}

		virtual void PrepareSet(int nSamples = defaultSetSize, int N = 0) {
			this->nSamples = nSamples > 0 ? nSamples : defaultSetSize;
			_N = N > 0 ? N : 0;
			current = 0;
		}

		virtual TestSample* GetSample() abstract;
	
	protected:
		int _N;
		int nSamples;
		int current;
	};

	template<class TSample>
	class RandomStringSamples : public RandomSamples<TSample>
	{
		RandomStringSamples(const RandomSamples&) = delete;
		RandomStringSamples& operator=(const RandomSamples&) = delete;
	public:
		RandomStringSamples(int maxLength) : maxLength(maxLength) {}

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

			return GetSample(move(strings[current++]));
		}

		virtual TestSample* GetSample(string&& str) abstract;
	
	protected:
		int maxLength;
		vector<string> strings;
	};



	template<typename NumType, class Distribution, class Engine=default_random_engine>
	void RandomNumbers(vector<NumType>& result, int count, NumType min, NumType max);

	template<typename IntType = int, class Engine=default_random_engine> 
	void UniformIntNumbers(vector<IntType>& result, int count, IntType min, IntType max) {
		return RandomNumbers<IntType, uniform_int_distribution<IntType>, Engine>(result, count, min, max);
	}

	extern const string cLetters;
	void RandomStrings(vector<string>& result, int count, int maxLength, bool fixedLength, string chars=cLetters);
} // namespace LeetCode

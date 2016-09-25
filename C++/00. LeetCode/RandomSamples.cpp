#include "RandomSamples.h"
#include <chrono>
#include <sstream>

namespace LeetCode
{

	//template<typename IntType, class Engine> 
	//void UniformIntNumbers(vector<IntType>& result, int count, IntType min, IntType max)
	//{
	//	Engine engine;
	//	int seed = (int)chrono::system_clock::now().time_since_epoch().count();
	//	engine.seed(seed);

	//	uniform_int_distribution<IntType> distribution(min, max);
	//	auto random = bind(distribution, engine);

	//	result.clear();
	//	for (int i = 0; i < count; i++) {
	//		result.push_back(random());
	//	}
	//}

	template<typename NumType, class Distribution, class Engine>
	void RandomNumbers(vector<NumType>& result, int count, NumType min, NumType max)
	{
		Engine engine;
		int seed = (int)chrono::system_clock::now().time_since_epoch().count();
		engine.seed(seed);

		Distribution distribution(min, max);
		auto random = bind(distribution, engine);

		result.clear();
		for (int i = 0; i < count; i++) {
			result.push_back(random());
		}
	}


	template void UniformIntNumbers<int, default_random_engine>(vector<int>& result, int count, int min, int max);
	template void UniformIntNumbers<unsigned long long, default_random_engine>(
		vector<unsigned long long>& result, int count, unsigned long long min, unsigned long long max);

	template void RandomNumbers<int, uniform_int_distribution<int>, default_random_engine>(vector<int>& result, int count, int min, int max);
	template void RandomNumbers<unsigned long long, uniform_int_distribution<unsigned long long>, default_random_engine>(
		vector<unsigned long long>& result, int count, unsigned long long min, unsigned long long max);

	const string cLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZ";

	void RandomStrings(vector<string>& result, int count, int maxLength, bool fixedLength, string chars)
	{
		vector<int> randomlength;
		if (!fixedLength) {
			UniformIntNumbers(randomlength, count, 0, maxLength);
		}
		
		result.clear();
		int charsCount = chars.length();
		for (int i = 0; i < count; i++) {
			vector<int> randomInd;
			int len = fixedLength ? maxLength : randomlength[i];
			UniformIntNumbers(randomInd, len, 0, charsCount-1);
			string str;
			for (int k = 0; k < len; k++) {
				int ind = randomInd[k];
				str += chars[ind];
			}
			result.push_back(str);
		}
	}


} // namespace LeetCode

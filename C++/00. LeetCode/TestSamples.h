#pragma once
#include "LeetCode.h"
#include <utility>

using namespace std;

namespace LeetCode
{
	enum class TestStatus;
	template<class TSample> class ITester;


	template<typename TResult, typename... TArgs>
	class TestSample
	{
		TestSample(const TestSample&) = delete;
		TestSample& operator = (const TestSample&) = delete;
	public:
		typedef TResult Result_t;
		typedef tuple<TArgs...> Args_t;

		///.TestSample() = default;
		TestSample(TArgs&&... args);
		TestSample(TArgs&&... args, TResult&& expected);
		TestSample(TestSample&& in);
		TestSample& operator = (TestSample&& in);

		~TestSample();

		int NumArgs() const { return sizeof...(TArgs); }
		const Args_t& Args() const { return args; }
		Args_t& Args() { return args; }
		template<size_t k> auto Arg() { return get<k>(args); }
		TestStatus Status() const { return status; }
		Result_t* Expected() const { return expected; }
		Result_t* Result() const { return result; }
		void SetResult(Result_t&& result);
		void SetStatus(TestStatus status);
		
	protected:
		Args_t args;
		Result_t* expected;
		Result_t* result;
		TestStatus status;
	};


	template<class TSample>
	class TestSamples : public vector<TSample*>
	{
		TestSamples(const TestSamples&) = delete;
		TestSamples& operator=(const TestSamples&) = delete;
		void Init(const initializer_list<TSample*> &il);
		void Destroy();
	public:
		TestSamples(size_t capacity = 0);
		TestSamples(const initializer_list<TSample*> &il);
//		TestSamples(const initializer_list<TSample> &il);
		~TestSamples();

		TestSamples& operator=(const initializer_list<TSample*> &il);
	};

}; // namespace LeetCode

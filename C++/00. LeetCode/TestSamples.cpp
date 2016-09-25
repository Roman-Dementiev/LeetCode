#include "TestSamples.h"

namespace LeetCode {

	template<typename TResult, typename... TArgs>
	TestSample<TResult, TArgs...>::~TestSample()
	{
		delete expected;
		delete result;
	}

	template<typename TResult, typename... TArgs>
	TestSample<TResult, TArgs...>::TestSample(TArgs&&... args) :
		args(forward<TArgs>(args)...),
		expected(nullptr),
		result(nullptr),
		status(TestStatus::Unknown)
	{
	}

	template<typename TResult, typename... TArgs>
	TestSample<TResult, TArgs...>::TestSample(TArgs&&... args, TResult&& expected) :
		TestSample(forward<TArgs>(args)...)
	{
		this->expected = new TResult(forward<TResult>(expected));
	}

	template<typename TResult, typename... TArgs>
	TestSample<TResult, TArgs...>::TestSample(TestSample&& in) :
		args(forward<decltype(args)>(in.args)),
		expected(in.expected),
		result(in.result),
		status(in.status)
	{
		in.expected = nullptr;
		in.result = nullptr;
		in.status = TestStatus::Unknown;
	}

	template<typename TResult, typename... TArgs>
	TestSample<TResult, TArgs...>& TestSample<TResult, TArgs...>::operator = (TestSample&& in)
	{
		delete expected;
		delete result;

		args = forward<decltype(args)>(in.args);
		expected = in.expected;
		result = in.result;
		status = in.status;
		in.expected = nullptr;
		in.result = nullptr;
		in.status = TestStatus::Unknown;
		return *this;
	}

	template<typename TResult, typename... TArgs>
	void TestSample<TResult, TArgs...>::SetResult(Result_t&& result)
	{
		this->result = new TResult(move(result));
	}

	template<typename TResult, typename... Args>
	void TestSample<TResult, Args...>::SetStatus(TestStatus status)
	{
		this->status = status;
	}


	template<class TSample>
	TestSamples<TSample>::TestSamples(size_t capacity) :
		vector(capacity + 1, nullptr)
	{
	}

	template<class TSample>
	TestSamples<TSample>::TestSamples(const initializer_list<TSample*> &il) :
		vector(il.size() + 1)
	{
		Init(il);
	}

	//template<class TSample>
	//TestSamples<TSample>::TestSamples(const initializer_list<TSample> &il) :
	//	vector(il.size() + 1)
	//{
	//	int i = 0;
	//	for (auto it = il.begin(); it != il.end(); it++) {
	//		const TSample& sample = *it;
	//		at(i++) = new TSample(move(sample));
	//	}

	//	while (i < size()) {
	//		at(i++) = nullptr;
	//	}
	//}


	template<class TSample>
	TestSamples<TSample>::~TestSamples()
	{
		Destroy();
	}

	template<class TSample>
	TestSamples<TSample>& TestSamples<TSample>::operator=(const initializer_list<TSample*> &il)
	{
		Destroy();
		Init(il);
		return *this;
	}

	template<class TSample>
	void TestSamples<TSample>::Init(const initializer_list<TSample*> &il)
	{
		if (il.size() >= size()) {
			resize(il.size() + 1);
		}

		int i = 0;
		for (auto it = il.begin(); it != il.end(); it++) {
			TSample* sample = *it;
			if (sample == nullptr)
				break;
			at(i++) = sample;
		}

		while (i < size()) {
			at(i++) = nullptr;
		}
	}

	template<class TSample>
	void TestSamples<TSample>::Destroy()
	{
		for (auto it = begin(); it != end(); it++) {
			delete *it;
		}
	}


#define TEST_TYPE1(TResult, TArg1)\
	template class TestSample<TResult, TArg1>;\
	template class TestSamples<TestSample<TResult, TArg1>>;

#define TEST_TYPE2(TResult, TArg1, TArg2)\
	template class TestSample<TResult, TArg1, TArg2>;\
	template class TestSamples<TestSample<TResult, TArg1, TArg2>>;

#define TEST_TYPE3(TResult, TArg1, TArg2, TArg3)\
	template class TestSample<TResult, TArg1, TArg2, TArg3>;\
	template class TestSamples<TestSample<TResult, TArg1, TArg2, TArg3>>;

#include "TestTypes.h"

} // namespace LeetCode





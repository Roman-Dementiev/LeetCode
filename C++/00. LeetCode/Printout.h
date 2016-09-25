#pragma once
#include "LeetCode.h"
#include <iostream>

namespace LeetCode
{
	template<typename T>
	class PrintoutRef
	{
	public:
		typedef T Value_t;
		typedef const T& Ref_t;

		PrintoutRef(const T& ref, PrintoutMode mode = PrintoutMode::Default) : ref(ref), mode(mode) {}
		const T* operator ->() const { return &ref; }
		const T& operator *() const { return ref; }

	protected:
		Ref_t ref;
		PrintoutMode mode;
	};

	template<typename T>
	class Printout : public PrintoutRef<T>
	{
		PrintoutMode mode;
	public:
		Printout(const T& ref, PrintoutMode mode = PrintoutMode::Default) : PrintoutRef(ref, mode) {}

		friend ostream& operator << (ostream& out, const Printout<T>& print) {
			return out << print.ref;
		}
	};

	template<>
	class Printout<string> : public PrintoutRef<string>
	{
	public:
		Printout(const string& str, PrintoutMode mode = PrintoutMode::Default) : PrintoutRef(str, mode) {}

		friend ostream& operator << (ostream& out, const Printout<string>& print) {
			return out << "\"" << print.ref << "\"";
		}
	};

	template<typename T>
	class Printout<List<T>> : public PrintoutRef<List<T>>
	{
	public:
		Printout(const List<T>& list, PrintoutMode mode = PrintoutMode::Default) : PrintoutRef(list, mode) {}

		friend ostream& operator << (ostream& out, const Printout<List<T>>& print)
		{
			PrintoutMode mode = print.mode;
			ListNode<T>* node = print->Head();
			out << ((mode == PrintoutMode::Json) ? "[" : "{");
			if (node != nullptr) {
				out << Printout<T>(node->val, mode);
				while (node->next != nullptr) {
					if (mode == PrintoutMode::Default) {
						out << "->";
					} else {
						out << ", ";
					}
					node = node->next;
					out << Printout<T>(node->val, mode);
				}
			}
			out << ((mode == PrintoutMode::Json) ? "]" : "}");
			return out;
		}
	};

	template<typename T>
	class Printout<Range<T>> : public PrintoutRef<Range<T>>
	{
	public:
		Printout(const Range<T>& range, PrintoutMode mode = PrintoutMode::Default) : PrintoutRef(range, mode) {}

		friend ostream& operator << (ostream& out, const Printout& print)
		{
			PrintoutMode mode = print.mode;
			out << ((mode == PrintoutMode::Uniform) ? "{" : "[");
			if (print->Length() > 0) {
				auto item = (*print)[0];
				out << Printout<decltype(item)>(item, mode);
				for (int i = 1; i < print->Length(); i++) {
					auto item = (*print)[i];
					out << ", " << Printout<decltype(item)>(item, mode);
				}
			}
			return out << ((mode == PrintoutMode::Uniform) ? "}" : "]");
		}
	};

	template<typename T>
	class Printout<vector<T>> : public PrintoutRef<vector<T>>
	{
	public:
		Printout(const vector<T>& array, PrintoutMode mode = PrintoutMode::Default) : PrintoutRef(array, mode) {}

		friend ostream& operator << (ostream& out, const Printout& print)
		{
			out << Printout<Range<T>>(Range<T>(*print, 0, print->size()), print.mode);
			return out;
		}
	};

	template<class Tuple, int Last>
	class PrintArgs
	{
	public:
		static void Print(ostream& out, const Tuple& args, PrintoutMode mode) {
			PrintArgs<Tuple, Last-1>::Print(out, args, mode);
			auto last = get<Last>(args);
			Printout<decltype(last)> print(last, mode);
			out << ", " << print;
		}
	};
	
	template<class Tuple>
	class PrintArgs<Tuple, 0>
	{
	public:
		static void Print(ostream& out, const Tuple& args, PrintoutMode mode) {
			auto first = get<0>(args);
			Printout<decltype(first)> print(first, mode);
			out << print;
		}
	};

	template<typename... TArgs>
	class Printout<tuple<TArgs...>> : public PrintoutRef<tuple<TArgs...>>
	{
	public:
		Printout(const tuple<TArgs...>& args, PrintoutMode mode = PrintoutMode::Default) : PrintoutRef(args, mode) {}

		friend ostream& operator << (ostream& out, const Printout& print)
		{
			PrintArgs<tuple<TArgs...>, sizeof...(TArgs)-1>::Print(out, print.ref, print.mode);
			return out;
		}
	};

	template<typename TResult, typename... TArgs>
	class Printout<TestSample<TResult, TArgs...>> : PrintoutRef<TestSample<TResult, TArgs...>>
	{
		bool printArgs;
		bool printResult;
		bool printStatus;
		bool printFailed;
	public:
		Printout(const TestSample<TResult, TArgs...>& sample, PrintoutMode mode = PrintoutMode::Default,
				bool printArgs = true, bool printResult = true, bool printStatus = true, bool printFailed = true
			) : 
			PrintoutRef(sample, mode), 
			printArgs(printArgs), printResult(printResult), printStatus(printStatus), printFailed(printFailed)
		{}
	};
}

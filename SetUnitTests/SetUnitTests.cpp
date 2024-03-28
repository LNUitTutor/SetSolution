#include "pch.h"
#include "CppUnitTest.h"
#include "..\SetClass\Set.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*
	Set<T>& operator=(const Set<T>& other);
	int Size() const { return this->size; }
	bool contain(const T& x)
	Set<T> set_union(const Set<T>& other);
	Set<T> intersect(const Set<T>& other);
	Set<T> difference(const Set<T>& other);
	void printOn(std::ostream& os) const
	T* to_array() const
*/
template <typename T>
bool AreEqual(T* expected, T* actual, int size)
{
	for (int i = 0; i < size; ++i)
		if (expected[i] != actual[i]) return false;
	return true;
}
namespace SetUnitTests
{
	TEST_CLASS(SetCreationTests)
	{
	public:
		
		TEST_METHOD(TestDefaultCreation)
		{
			Set<int> A;
			Set<double> B;
			Set<char> C;
			Assert::AreEqual(0, A.size());
			Assert::AreEqual(0, B.size());
			Assert::AreEqual(0, C.size());
		}
		TEST_METHOD(TestAnElementCreation)
		{
			Set<int> A(5);
			Set<double> B(2.71);
			Set<char> C('C');
			Assert::AreEqual(1, A.size());
			Assert::IsTrue(A.contain(5));
			Assert::AreEqual(1, B.size());
			Assert::IsTrue(B.contain(2.71));
			Assert::AreEqual(1, C.size());
			Assert::IsTrue(C.contain('C'));
		}
		TEST_METHOD(TestARangeCreation)
		{
			int a[] = { 1, 1, 1, 1, 1 };
			int b[] = { 1, 2, 3, 4, 5 };
			int c[] = { 10, 9, 8, 3, 4, 5, 7, 6, 1, 2, 1, 2, 3 };
			Set<int> A(a, 5);
			Set<int> B(b, 5);
			Set<int> C(c, sizeof c / sizeof * c);
			Assert::AreEqual(1, A.size());
			Assert::IsTrue(A.contain(1));
			Assert::AreEqual(5, B.size());
			int* d = B.to_array();
			//for (int i = 0; i < 5; ++i) Assert::AreEqual(b[i], d[i]);
			Assert::IsTrue(AreEqual(b, d, 5));
			delete[] d;
			Assert::AreEqual(10, C.size());
			int* e = C.to_array();
			for (int i = 0; i < 10; ++i) Assert::AreEqual(i + 1, e[i]);
			delete[] e;
		}
		TEST_METHOD(TestCopyCreation)
		{
			int b[] = { 1, 2, 3, 4, 5 };
			Set<int> B(b, 5);
			Set<int> C(B);
			Assert::AreEqual(B.size(), C.size());
			int* e = C.to_array();
			//for (int i = 0; i < 5; ++i) Assert::AreEqual(b[i], e[i]);
			Assert::IsTrue(AreEqual(b, e, 5));
			delete[] e;
		}
	};
	TEST_CLASS(SetAddRemoveTests)
	{
	public:
		TEST_METHOD(TestAddAnElement)
		{
			Set<int> A(1);
			Assert::AreEqual(1, A.size());
			Assert::IsTrue(A.contain(1));
			Assert::IsFalse(A.contain(5));
			Assert::IsFalse(A.contain(4));
			A.add(4);
			Assert::AreEqual(2, A.size());
			Assert::IsFalse(A.contain(5));
			Assert::IsTrue(A.contain(4));
			A.add(5);
			Assert::AreEqual(3, A.size());
			Assert::IsTrue(A.contain(5));
			Assert::IsTrue(A.contain(4));
			Assert::IsTrue(A.contain(1));
			A.add(5).add(5).add(1);
			Assert::AreEqual(3, A.size());
		}
		TEST_METHOD(TestAddRange)
		{
			Set<char> A;
			A.addRange("abracadabra", 11);
			Assert::AreEqual(5, A.size());
			char c[] = "abcdr";
			char* d = A.to_array();
			Assert::IsTrue(AreEqual(c, d, 5));
			delete[] d;
			std::string words[] = { "Hello", "world", "now", "Hello", "everybody" };
			Set<std::string> W;
			W.addRange(words, 5);
			Assert::AreEqual(4, W.size());
			Assert::IsTrue(W.contain("now"));
		}
		TEST_METHOD(TestRemove)
		{
			Set<char> A;
			A.addRange("abracadabra", 11);
			Assert::AreEqual(5, A.size());
			A.remove('a');
			Assert::AreEqual(4, A.size());
			Assert::IsFalse(A.contain('a'));
			A.remove('d');
			Assert::AreEqual(3, A.size());
			Assert::IsFalse(A.contain('d'));
			A.remove('r');
			Assert::AreEqual(2, A.size());
			Assert::IsFalse(A.contain('r'));
			Assert::ExpectException<std::runtime_error>([&A] { A.remove('a'); });
			Assert::ExpectException<std::runtime_error>([&A] { A.remove('f'); });
			Assert::AreEqual(2, A.size());
		}
		TEST_METHOD(TestClear)
		{
			Set<double> A;
			Assert::AreEqual(0, A.size());
			A.clear();
			Assert::AreEqual(0, A.size());
			A.add(1.5).add(2.25).add(0.5).add(1.).add(0.25).add(5);
			Assert::AreEqual(6, A.size());
			A.clear();
			Assert::AreEqual(0, A.size());
			A.add(1.5).add(2.25);
			Assert::AreEqual(2, A.size());
			Assert::IsTrue(A.contain(1.5));
			Assert::IsTrue(A.contain(2.25));
		}
	};
	TEST_CLASS(TestOperation)
	{
		TEST_METHOD(Test)
		{

		}
	};
}

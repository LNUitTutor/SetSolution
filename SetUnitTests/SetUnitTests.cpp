#include "pch.h"
#include "CppUnitTest.h"
#include "..\SetClass\Set.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		TEST_METHOD(TestUnion)
		{
			int a[] = { 1, 3, 5, 7, 9 };
			int b[] = { 1, 2, 3, 4, 5 };
			int c[] = { 4, 5, 6, 7, 8, 9, 10 };
			Set<int> A(a, 5);
			Set<int> B(b, 5);
			Set<int> C(c, sizeof c / sizeof * c);
			Set<int> D;
			Set<int> AUB = A.set_union(B);
			Set<int> BUA = B.set_union(A);
			int d[] = { 1, 2, 3, 4, 5, 7, 9 };
			int* ab = AUB.to_array();
			int* ba = BUA.to_array();
			Assert::IsTrue(AreEqual(d, ab, 7));
			Assert::IsTrue(AreEqual(d, ba, 7));
			delete[] ab; delete[] ba;
			Set<int> AUD = A.set_union(D);
			ab = AUD.to_array();
			Assert::IsTrue(AreEqual(a, ab, 5));
			Set<int> BUC = B.set_union(C);
			ba = BUC.to_array();
			for (int i = 0; i < 10; ++i) Assert::AreEqual(i + 1, ba[i]);
			delete[] ab; delete[] ba;
		}
		TEST_METHOD(TestIntersection)
		{
			int a[] = { 1, 3, 5, 7, 9 };
			int b[] = { 1, 2, 3, 4, 5 };
			int c[] = { 4, 5, 6, 7, 8, 9, 10 };
			Set<int> A(a, 5);
			Set<int> B(b, 5);
			Set<int> C(c, sizeof c / sizeof * c);
			Set<int> D;
			Set<int> AOB = A.intersect(B);
			Set<int> BOA = B.intersect(A);
			int d[] = { 1, 3, 5 };
			int* ab = AOB.to_array();
			int* ba = BOA.to_array();
			Assert::IsTrue(AreEqual(d, ab, 3));
			Assert::IsTrue(AreEqual(d, ba, 3));
			delete[] ab; delete[] ba;
			Set<int> AOD = A.intersect(D);
			Assert::AreEqual(0, AOD.size());
			Set<int> BOC = B.intersect(C);
			Assert::AreEqual(2, BOC.size());
			Assert::IsTrue(BOC.contain(4));
			Assert::IsTrue(BOC.contain(5));
		}
		TEST_METHOD(TestDifference)
		{

			int a[] = { 1, 3, 5, 7, 9 };
			int b[] = { 1, 2, 3, 4, 5 };
			int c[] = { 4, 5, 6, 7, 8, 9, 10 };
			Set<int> A(a, 5);
			Set<int> B(b, 5);
			Set<int> C(c, sizeof c / sizeof * c);
			Set<int> D;
			Set<int> A_B = A.difference(B);
			Set<int> B_A = B.difference(A);
			int d[] = { 7, 9, 2, 4 };
			int* ab = A_B.to_array();
			int* ba = B_A.to_array();
			Assert::IsTrue(AreEqual(d, ab, 2));
			Assert::IsTrue(AreEqual(d + 2, ba, 2));
			delete[] ab; delete[] ba;
			Set<int> A_D = A.difference(D);
			ab = A_D.to_array();
			Assert::IsTrue(AreEqual(a, ab, 5));
			Set<int> B_C = B.difference(C);
			ba = B_C.to_array();
			for (int i = 0; i < 3; ++i) Assert::AreEqual(i + 1, ba[i]);
			delete[] ab; delete[] ba;
		}
		TEST_METHOD(TestPrint)
		{
			Set<int> A;
			std::ostringstream os;
			A.printOn(os);
			Assert::AreEqual("Set{ }", os.str().c_str());
			os.seekp(0);
			A.add(1).add(2).add(3).add(4).printOn(os);
			Assert::AreEqual("Set{ 1 2 3 4 }", os.str().c_str());
			os.seekp(0);
			Set<std::string> B;
			B.add("Hello").add("World").add("We").add("Are").add("Going");
			B.printOn(os);
			Assert::AreEqual("Set{ Are Going Hello We World }", os.str().c_str());
		}
	};
}

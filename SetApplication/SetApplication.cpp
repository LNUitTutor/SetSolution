#include <iostream>
#include "Classes.h"
#include "..\SetClass\Set.h"

void TestFirst();
void TestSecond();
void EratospheneSieve();
void EratospheneSieve_1();

int main()
{

   /* TestFirst();
    TestSecond();*/
    EratospheneSieve();
    EratospheneSieve_1();

}
void TestFirst()
{
    int a[5] = {1, 8, 1, 5, 0};
    Set<int> A(a, 5);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    int* d = A.to_array();
    for (int i = 0; i < A.size(); ++i) std::cout << ' ' << d[i];
    std::cout << '\n';
    delete[] d;
    int b[4] = { 2, 8, 3, 8 };
    Set<int, std::greater<int>> B(b, 4);
    std::cout << " B = " << B << " has size " << B.size() << '\n';
    Set<int, std::greater<int>> C = A.set_union(B);
    std::cout << " A+B = " << C << " has size " << C.size() << '\n';
    A.remove(1);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    A.remove(0);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    A.remove(8);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    try
    {
        A.remove(10);
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    for (int i = 3; i < 37; i += 5) A.add(i);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    Set<int, std::greater<int>> P = A.intersect(B);
    std::cout << " A*B = " << P << " has size " << P.size() << '\n';
    Set<int, std::greater<int>> R = A.intersect(C);
    std::cout << " A*C = " << R << " has size " << R.size() << '\n';
    Set<int, std::greater<int>> Q = A.difference(B.add(33));
    std::cout << " A-B-{33} = " << Q << " has size " << Q.size() << '\n';
    Q.clear();
    std::cout << " Q = " << Q << " has size " << Q.size() << '\n';
    int c[] = { 10, 9, 8, 3, 4, 5, 7, 6, 1, 2, 1, 2, 3 };
    Set<int, std::greater<int>> C1(c, sizeof c / sizeof * c);
    std::cout << " C1 = " << C1 << " has size " << C1.size() << '\n';
    int* e = C1.to_array();
    for (int i = 1; i <= 10; ++i) std::cout << e[i - 1];
    std::cout << '\n';
    delete[] e;
    Set<int>::Iterator start = C1.begin();
    Set<int>::Iterator stop = C1.end();
    while (start != stop)
    {
        std::cout << *start << ' ';
        ++start;
    }
    std::cout << '\n';
  
    Person p[] = { Person("Ivan",19), Person("Maria",18), Person("Adam",35),
        {"Steph", 42 }, { "Silvie", 40 }};
    const int pn = sizeof p / sizeof * p;
    Set<Person, NameCompare> F(p, pn);
    std::cout << " F = " << F << " has size " << F.size() << '\n';
    Set<Person, AgeCompare> G(p, pn);
    std::cout << " G = " << G << " has size " << G.size() << '\n';
}
void TestSecond()
{
    Set<int> A;
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    int a[5] = { 1, 8, 1, 5, 0 };
    A.add(5);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    A.addRange(a, 5);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    Set<int> B(A);
    std::cout << " B = " << B << " has size " << B.size() << '\n';
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    for (int x : a)
    {
        std::cout << x << " belongs " << A.contain(x) << '\n';
    }
    std::cout << 10 << " belongs " << A.contain(10) << '\n';
}

void EratospheneSieve()
{
    std::cout << "Input the upper integer: ";
    unsigned n; std::cin >> n;
    // build a total set
    Set<unsigned> prime;
    for (unsigned i = 2; i <= n; ++i) prime.add(i);
    // get the iterators to enumerate through the set
    Set<unsigned>::Iterator start = prime.begin();
    Set<unsigned>::Iterator stop = prime.end();
    while (start != stop)
    {
        unsigned member = *start;
        // every next multilie is bigger then previous one by the adder
        unsigned adder = member;
        member += adder;
        while (member <= n)
        {
            // remove can causes an exception
            try { prime.remove(member); }
            catch (...) {}
            // next multiplie
            member += adder;
        }
        ++start; // next prime number in the set
    }
    std::cout << "prime = " << prime << '\n';
    std::cout << "size = " << prime.size() << '\n';
}
void EratospheneSieve_1()
{
    std::cout << "Input the upper integer: ";
    unsigned n; std::cin >> n;
    // build a total set
    Set<unsigned> prime;
    for (unsigned i = 2; i <= n; ++i) prime.add(i);
    // start with the first prime number
    unsigned member = 2;
    while (member < n)
    {
        // every multiple of the member has form "member*k" where k=2,3,...
        unsigned k = 2;
        unsigned next_number = member * k;
        // remove present multiplies
        while (next_number <= n)
        {
            if (prime.contain(next_number)) prime.remove(next_number);
            ++k;
            next_number = member * k;
        }
        // look for the next prime memeber in the set
        do
        {
            ++member;
        } while (!prime.contain(member) && member < n);
    }
    std::cout << "prime = " << prime << '\n';
    std::cout << "size = " << prime.size() << '\n';
}
#include <iostream>
#include "..\SetClass\Set.h"

int main()
{
    //Set<int> A;
    //std::cout << " A = " << A << " has size " << A.size() << '\n';
    //int a[5] = { 1, 8, 1, 5, 0 };
    //A.add(5);
    //std::cout << " A = " << A << " has size " << A.size() << '\n';
    //A.addRange(a, 5);
    //std::cout << " A = " << A << " has size " << A.size() << '\n';
    //Set<int> B(A);
    //std::cout << " B = " << B << " has size " << B.size() << '\n';
    //std::cout << " A = " << A << " has size " << A.size() << '\n';
    //for (int x : a)
    //{
    //    std::cout << x << " belongs " << A.contain(x) << '\n';
    //}
    //std::cout << 10 << " belongs " << A.contain(10) << '\n';
    /*int a[5] = {1, 8, 1, 5, 0};
    Set<int> A(a, 5);
    std::cout << " A = " << A << " has size " << A.size() << '\n';
    int* d = A.to_array();
    for (int i = 0; i < A.size(); ++i) std::cout << ' ' << d[i];
    std::cout << '\n';
    delete[] d;
    int b[4] = { 2, 8, 3, 8 };
    Set<int> B(b, 4);
    std::cout << " B = " << B << " has size " << B.size() << '\n';
    Set<int> C = A.set_union(B);
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
    Set<int> P = A.intersect(B);
    std::cout << " A*B = " << P << " has size " << P.size() << '\n';
    Set<int> R = A.intersect(C);
    std::cout << " A*C = " << R << " has size " << R.size() << '\n';
    Set<int> Q = A.difference(B.add(33));
    std::cout << " A-B-{33} = " << Q << " has size " << Q.size() << '\n';
    Q.clear();
    std::cout << " Q = " << Q << " has size " << Q.size() << '\n';
    int c[] = { 10, 9, 8, 3, 4, 5, 7, 6, 1, 2, 1, 2, 3 };
    Set<int> C1(c, sizeof c / sizeof * c);
    std::cout << " C1 = " << C1 << " has size " << C1.size() << '\n';
    int* e = C1.to_array();
    for (int i = 1; i <= 10; ++i) std::cout << e[i - 1]; std::cout << '\n';
    delete[] e;
    Set<int>::Iterator start = C1.begin();
    Set<int>::Iterator stop = C1.end();
    while (start != stop)
    {
        std::cout << *start << ' ';
        ++start;
    }
    std::cout << '\n';*/

    std::cout << "Input the upper integer: ";
    unsigned n; std::cin >> n;
    Set<unsigned> prime;
    for (unsigned i = 2; i <= n; ++i) prime.add(i);
    Set<unsigned>::Iterator start = prime.begin();
    Set<unsigned>::Iterator stop = prime.end();
    while (start != stop)
    {
        unsigned member = *start;
        unsigned adder = member;
        member += adder;
        while (member <= n)
        {
            try { prime.remove(member); }
            catch (...) {}
            member += adder;
        }
        ++start;
    }
    std::cout << "prime = " << prime << '\n';
}
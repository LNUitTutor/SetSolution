#include <iostream>
#include "..\SetClass\Set.h"

int main()
{
    //Set<int> A;
    //std::cout << " A = " << A << " has size " << A.Size() << '\n';
    //int a[5] = { 1, 8, 1, 5, 0 };
    //A.add(5);
    //std::cout << " A = " << A << " has size " << A.Size() << '\n';
    //A.addRange(a, 5);
    //std::cout << " A = " << A << " has size " << A.Size() << '\n';
    //Set<int> B(A);
    //std::cout << " B = " << B << " has size " << B.Size() << '\n';
    //std::cout << " A = " << A << " has size " << A.Size() << '\n';
    //for (int x : a)
    //{
    //    std::cout << x << " belongs " << A.contain(x) << '\n';
    //}
    //std::cout << 10 << " belongs " << A.contain(10) << '\n';
    int a[5] = { 1, 8, 1, 5, 0 };
    Set<int> A(a, 5);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    int b[4] = { 2, 8, 3, 8 };
    Set<int> B(b, 4);
    std::cout << " B = " << B << " has size " << B.Size() << '\n';
    Set<int> C = A.set_union(B);
    std::cout << " A+B = " << C << " has size " << C.Size() << '\n';
    A.remove(1);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    A.remove(0);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    A.remove(8);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    try
    {
        A.remove(10);
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    for (int i = 3; i < 37; i += 5) A.add(i);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    Set<int> P = A.intersect(B);
    std::cout << " A*B = " << P << " has size " << P.Size() << '\n';
    Set<int> R = A.intersect(C);
    std::cout << " A*C = " << R << " has size " << R.Size() << '\n';
    Set<int> Q = A.difference(B.add(33));
    std::cout << " A-B-{33} = " << Q << " has size " << Q.Size() << '\n';
    Q.clear();
    std::cout << " Q = " << Q << " has size " << Q.Size() << '\n';
}
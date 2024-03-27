#include <iostream>
#include "Set.h"

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
    std::cout << " C = " << C << " has size " << C.Size() << '\n';
}
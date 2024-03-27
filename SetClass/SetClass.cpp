#include <iostream>
#include "Set.h"

int main()
{
    std::cout << "Hello World!\n";
    Set<int> A;
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    int a[5] = { 1, 8, 1, 5, 0 };
    A.add(5);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
    A.addRange(a, 5);
    std::cout << " A = " << A << " has size " << A.Size() << '\n';
}
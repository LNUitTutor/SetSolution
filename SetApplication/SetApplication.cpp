#include "Functions.h"

int main()
{
   /* TestFirst();
    TestSecond();*/
    /*EratospheneSieve();
    EratospheneSieve_1();*/
    //Задано рядок літер. Надрукувати:
    std::cin.get();
    std::string given;
    std::cout << "\n Input a string: ";
    getline(std::cin, given);
    //перше входження кожної літери зі збереженням їхнього початкового порядку
    PrintFirstEntry(given);
    //усі літери, які зустрічаються в рядку не менше двох разів
    PrintMultipleLetters(given);
    //усі літери, які зустрічаються тільки один раз
    PrintSingleLetters(given);
}

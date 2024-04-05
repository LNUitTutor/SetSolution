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

    Shops Glove{ {Product::bread, Product::water, Product::salt, Product::cheese, Product::milk, Product::butter },
        { Product::bread, Product::water, Product::salt, Product::fish, Product::milk },
        { Product::bread, Product::water, Product::salt, Product::tea, Product::coffee, Product::sugar },
        { Product::bread, Product::water, Product::salt, Product::meat },
        { Product::bread, Product::water, Product::sugar, Product::fish } };
    std::cout << "The complete list of products:\n";
    for (Product pr = Product::bread; pr <= Product::caviar;
        pr = Product((int)pr + 1)) std::cout << int(pr) + 1 << ". " << pr << '\n';
    std::cout << "\n Products are everywhere in Glove shops:\n"
        << PresentEverywhere(Glove) << '\n';
    std::cout << "\n Products are somewhere in Glove shops:\n"
        << PresentSomewhere(Glove) << '\n';
    std::cout << "\n Products are absent in Glove shops:\n"
        << Absent(Glove) << '\n';
}

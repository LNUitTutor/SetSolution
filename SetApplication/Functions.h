#pragma once
#include <string>
#include <iostream>
#include "..\SetClass\Set.h"

void TestFirst();
void TestSecond();
void EratospheneSieve();
void EratospheneSieve_1();

//Надрукувати перше входження кожної літери зі збереженням їхнього початкового порядку:
//  abracadabra --> abrcd
void PrintFirstEntry(std::string word);

//Надрукувати усі літери, які зустрічаються в рядку не менше двох разів:
//  abracadabra --> abr
void PrintMultipleLetters(std::string word);

//Надрукувати усі літери, які зустрічаються тільки один раз: abracadabra --> cd
void PrintSingleLetters(std::string word);

// Нехай Продукт = { хліб, масло, молоко, сир, м’ясо, риба, сіль, цукор, чай, кава, вода };
// Асортимент = множина продуктів, наявних у магазині;
// Магазини – сукупність асортиментів.

enum class Product { bread, butter, milk, cheese, meat, fish, salt, sugar, tea, coffee, water, caviar
};
using Assortment = Set<Product>;
const int n = 5;
using Shops = Assortment[n];

std::ostream& operator<<(std::ostream& os, Product pr);

//Знайдіть продукти, які є в кожному магазині. 
Assortment PresentEverywhere(Shops s);

//Знайдіть продукти, які є хоча б в одному магазині.
Assortment PresentSomewhere(Shops s);

//Знайдіть продукти, які відсутні в усіх магазинах.
Assortment Absent(Shops s);
#pragma once
#include <string>

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
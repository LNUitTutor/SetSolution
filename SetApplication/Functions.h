#pragma once
#include <string>
#include <iostream>
#include "..\SetClass\Set.h"

void TestFirst();
void TestSecond();
void EratospheneSieve();
void EratospheneSieve_1();

//����������� ����� ��������� ����� ����� � ����������� ������� ����������� �������:
//  abracadabra --> abrcd
void PrintFirstEntry(std::string word);

//����������� �� �����, �� ������������ � ����� �� ����� ���� ����:
//  abracadabra --> abr
void PrintMultipleLetters(std::string word);

//����������� �� �����, �� ������������ ����� ���� ���: abracadabra --> cd
void PrintSingleLetters(std::string word);

// ����� ������� = { ���, �����, ������, ���, ����, ����, ���, �����, ���, ����, ���� };
// ���������� = ������� ��������, ������� � �������;
// �������� � ��������� �����������.

enum class Product { bread, butter, milk, cheese, meat, fish, salt, sugar, tea, coffee, water, caviar
};
using Assortment = Set<Product>;
const int n = 5;
using Shops = Assortment[n];

std::ostream& operator<<(std::ostream& os, Product pr);

//������� ��������, �� � � ������� �������. 
Assortment PresentEverywhere(Shops s);

//������� ��������, �� � ���� � � ������ �������.
Assortment PresentSomewhere(Shops s);

//������� ��������, �� ������ � ��� ���������.
Assortment Absent(Shops s);
#pragma once
#include <string>

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
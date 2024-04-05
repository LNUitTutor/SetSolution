#pragma once
#include <string>
struct Person
{
    std::string name;
    int age;
    Person(std::string s = "", int n = 0) :name(s), age(n) {}
};
std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << '(' << p.name << ' ' << p.age << ')';
    return os;
}
struct AgeCompare
{
    bool operator()(const Person& a, const Person& b)
    {
        return a.age < b.age;
    }
};
struct NameCompare
{
    bool operator()(const Person& a, const Person& b)
    {
        return a.name < b.name;
    }
};
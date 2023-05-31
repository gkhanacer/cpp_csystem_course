#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <set>
#include <fstream>
#include <list>
#include <tuple>
#include "../nutility.h"
#include <functional>

using namespace std;

struct Person {
public:
    Person() = default;
    Person(std::string name, int age) : m_name{std::move(name)}, m_age{std::move(age)} {}
    friend std::ostream& operator<<(std::ostream& os, const Person& per)
    {
        return os << per.m_name << "\t\t" << per.m_age;
    }
    std::string name()const {return m_name;};
    int age()const {return m_age;};
private:
    std::string m_name;
    int m_age;
};

int main(int argc, char const *argv[])
{   
    vector<Person> pvec;
    auto f = [] { 
            return Person{ rname(), rand() % 50 + 10}; 
        }; 
    
    rfill(pvec, 10000, f);
    sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2){
        return p1.name() < p2.name();
    });

    stable_sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2){
        return p1.age() < p2.age();
    });
    
    std::ofstream ofs { "list.txt" };
    print(pvec, ofs, "\n");
    return 0;
}

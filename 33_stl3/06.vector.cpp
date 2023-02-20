#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <set>
#include <list>
#include <tuple>

using namespace std;

template <typename T>
void print(T list) 
{
    auto iter = list.begin();
    while (iter != list.end()) 
    {
        cout << *iter++ << " ";
    }
    cout << "\n";
}

void printArray(const int *p, size_t size) {
    while(size--) {
        printf("%d ", *p++);
    }
    printf("\n");
}

void increaseMember(int *p, size_t size) {
    while(size--) {
        ++*p;
        ++p;
    }
}

int main(int argc, char const *argv[])
{   
    // ELEMANLARA ERISME

    // sequence contair'larin front islevleri ilk ogeye eristirir. back son ogeye eristirir
    vector<string> svec{"ali", "veli", "ayse", "fatma"};
    svec.front() += "can";
    svec.back() = "nuriye";
    print(svec);
    
    // const operator[] cagirilmasinda sorun yok, degistirirsen hata
    const vector<string> svec2 {"ali", "veli", "ayse", "fatma"};
    // svec2[4] = "merver";   //syntax error
    // svec2.front() += "can"; //syntax error
    // sve2c.back() = "nuriye";//syntax error

    // vectorun ilk adresini getirme : data() member function
    // c apisiyle kullanmak istersek cok ise yarar
    vector<int> ivec {2,3,45,6,8,9,8};
    printArray(ivec.data(), ivec.size());
    increaseMember(ivec.data(), ivec.size());
    printArray(ivec.data(), ivec.size());
    
    auto p1 = &ivec[0];
    auto p2 = &*ivec.begin();
    auto p3 = ivec.data();
    auto p4 = &ivec.front();

    // data ayni zamanda global bir fonsiyon
    std::data(ivec);

    return 0;
}

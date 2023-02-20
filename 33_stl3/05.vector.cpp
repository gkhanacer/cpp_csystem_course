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


int main(int argc, char const *argv[])
{   
    // reserver
    // BP: DIKKAT!
    // eger vectorun tutacgi deger sayisi bastan belli ise
    // fakat dongulser bir yapidan ogeler ekleniyorsa
    // reserver ile bastan capasity set edilir. gereksiz reallocation'dan kacinilir
    vector<int> ivec;
    ivec.reserve(2000); // 2000 elemana kadar realloation yok. 2000 olmayabilir (derleyiciye bagli)
    cout << "ivec.capacity() : " << ivec.capacity() << '\n';
    ivec.assign(100000, 2);
    cout << "ivec.capacity() : " << ivec.capacity() << '\n';
    // vector'un max capasity belirtilemez. dinamik dizi.


    // vector'deki ogelere eristiren fonksiyonlar
    vector<string> svec{"ali", "veli", "ayse", "fatma"};
    svec[3] += "can";
    cout << svec[2].size() << '\n';
    for (size_t i{}; i < svec.size(); ++i) {
        cout << svec[i]<< '\n';
    }
    // svec.operator[](0);
    
    // operator[] exception throw etmez!!! UB
    try{
        cout << svec[6].size() << '\n'; // UB DIKKAT!!!!! Gecersiz index ile erisimde throw yok!!!!!!
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    // at member function exception throw eder!!!
    try {
        cout << svec.at(6).size() << '\n';
    }
    catch(const std::exception& e)  {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

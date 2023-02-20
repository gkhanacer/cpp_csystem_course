#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <set>
#include <list>

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


class Myclass {
public:
    Myclass(std::initializer_list<int> ) {
        cout << "initlist" << '\n';
    }
    Myclass(int) {
        cout << "int" << '\n';
    }
    Myclass(int, int) {
        cout << "int, int" << '\n';
    }
};

int main(int argc, char const *argv[])
{   
    // initializer_list bir container degil!!!!

    // Cogunlukla container siniflarinin uye fonksiyonlarinda initializer_list kullaniliyor
    // Kendi siniflarimizda da kullanabiliriz

    // Eger bir sinifin ctor'unun tek parametresi bir initializer_list ise
    Myclass m {1, 2, 3, 4}; 
    vector<int> ivec {1, 2, 3, 4}; // vectorun de ctor'u var

    // initializer_list'in int'e gore overloading de ustunlugu var
    // hepsinde init_list cagirilir.
    // uniform init istisnasidir bu durum.
    Myclass m1 {};
    Myclass m2{12}; 
    Myclass m3{12, 13};
    Myclass m4{1, 2, 3};
    Myclass m5(12); 



    return 0;
}

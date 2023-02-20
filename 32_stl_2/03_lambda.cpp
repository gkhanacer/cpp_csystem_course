/*
Lambda expression oyle bir ifadedir ki 
derleyici bu ifade karigi bir sinif tanimlar (closure type),
ve ifadenin kendisini tanimladigi sinif turunden gecici nesne (closure object) olarak ele alir.
*/

#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>

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
    vector <string> svec{"ali", "veli", "gokhan", "ahmet"};
    vector<string> destvec(4);

    std::cout << "uzunlugu kac olanlar: ";
    size_t len;
    std::cin >> len;
    auto iter = copy_if(svec.begin(), svec.end(), destvec.begin(), 
        [len](const string& s){ return s.length() == len; }
    );
    // Burada [len] olusturulan sinifin ctoruna gonderilen arguman.
    // geri kalan ise operator()'un overload olan fonksiyonun kendisi

    std::cout << "hangi karakter olanlar: ";
    char c;
    std::cin >> c;
    auto iter2 = copy_if(svec.begin(), svec.end(), destvec.begin(), 
        [c](const string& s){ return s.find(c) != std::string::npos; }
    );

    print(destvec);
    return 0;
}
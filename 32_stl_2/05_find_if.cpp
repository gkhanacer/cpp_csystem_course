#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <set>

using namespace std;

/*
STL arama algorutmalari aranan deger bulunamadiginda kendisine gonderilen range'in end konumunu gonderir.
*/

template <typename InIter, typename T>
InIter Find(InIter beg, InIter end, const T& val)
{
    while (beg != end) {
        if (*beg == val)
            return beg;
        ++beg;
    }
    return  beg;
}

template <typename InIter, typename Pred>
InIter FindIf(InIter beg, InIter end, Pred f)
{
    while (beg != end) {
        if (f(*beg))
            return beg;
        ++beg;
    }
    return  beg;
}

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


bool has_unique_chars(const string s)
{
    return set<char>(s.begin(), s.end()).size() == s.size();
}

int main(int argc, char const *argv[])
{
    vector<string> svec {"ankara", "istanbul", "izmir", "antalya", "yozgat", "tunceli", "aydin"};
    print(svec);

    string town;
    cout << "aranan ili giriniz : ";
    cin >> town;

    // auto iter = find(svec.begin(), svec.end(), town);
    if (auto iter = find(svec.begin(), svec.end(), town); iter != svec.end()) // scope leakage onlendi! if initializer C++17
        cout << "bulundu : " << *iter << "\n";
    else
        cout << "bulunamadi\n";

    // butun karakterleri unique olan sehir isimleri
    if (auto iter = find_if(svec.begin(), svec.end(), has_unique_chars); iter != svec.end()) // scope leakage onlendi! if initializer C++17
        cout << "bulundu : " << *iter << "\n";
    else
        cout << "bulunamadi\n";

    // use lambda
    if (auto iter = find_if(svec.begin(), svec.end(), [](const string& s){
            return set<char>{s.begin(), s.end()}.size() == s.size();
        }); 
        iter != svec.end()) // scope leakage onlendi! if initializer C++17
        cout << "bulundu : " << *iter << "\n";
    else
        cout << "bulunamadi\n";

    


    return 0;



}

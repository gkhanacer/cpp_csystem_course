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

// compile time'da alternatif kod olusturmak ve kod secmek. DIKKAT compile time'da!
// type traits:
// - tag-dispatch
// - SFINAE
// - constexpr if
// ====
// consepts (C++20)

template <typename Iter>
void algo(Iter beg, Iter end) 
{
    // beg += 3; //runtime da random access iterator disinda bir iterator gelirse syntax error olur
    

}

// uzunlugu n olanlari kopyala
int main(int argc, char const *argv[])
{
    vector<string> ivec(1000);
    list<int> ilist(1000);

    auto iter = ivec.begin();
    auto iterList = ilist.begin();

    iter += 10;
    // iterList += 10; // bidirectional iter += yok. loop'u olusturup tek tek eklemek gerekir ya da...

    std::advance(iter, 10); // iteratoru n kadar ileri + ya da geri - tasir

    vector<string> svec {"ali", "eda", "can", "veli"};
    auto iter3  = svec.end();
    
    // std::cout << *iter3 << "\n"; // end()
    std::advance(iter3, -1); // veli
    std::cout << *iter3 << "\n"; // veli 
    std::advance(iter3, -3); // ali
    std::cout << *iter3 << "\n"; // ali

    auto iter_x = svec.begin() + 1;
    auto iter_y = svec.end();
    cout << distance(iter_x, iter_y);

     

    return 0; 
}


// std::advance iteratoru n kadar ileri + ya da geri - tasir
// std::distance iki iterator arasndaki distance
// std::next n kadar sonraki elemaninin iteratorunu ayrica dondurur
// std::prev n kadar oncdeku elemaninin iteratorunu ayrica dondurur
// std::iter_swap iterator konumundaki nesneleri/icerikleri swap ediyor
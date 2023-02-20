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

template <typename T>
class Myclass {
public:
    Myclass(T);
};

// vector()
// vector(const vector&)
// vector(vector&&)
// vector(size_t) // explicit 
// vector(size_t, T)
// vector(std::initializer_list<T>)

// Range ctor ; [first, last)
int main(int argc, char const *argv[])
{   
    vector<int> ivec {1, 2, 4, 5};
    vector<int> x(ivec.begin(), ivec.begin() + 2);
    print(x);

    int a[]{1,2,3,4,5,6,7,8};
    vector<int> x2 (a + 1, a + 3);
    print(x2);
  
    
    list<int> mylist {1,2,3,4,5};
    // list<double> x3 {mylist}; // bu gecersiz. farkli tiplerdedir
    // vector x3 {mylist}; // bu gecersiz. farkli tiplerdedir
    vector<int> x4(mylist.begin(), mylist.end()); // iste iterator'un guzelligi burada devreye giriyor. template base olduklari icin 
    print(x4);
    
    // c type arrayleri almak icin global begin ve end range fonsiyonlari da kullanilabilir
    const char* p[] = {"ali", "veli", "ayse", "fatma"};
    vector<string> svec(std::begin(p), std::end(p)); 
    print(svec);


    // vector(size_t) ctoru explicit
    // vector<int> ivec = 60; // bu gecerli degil
 
    // C++17 CTAD: Class Template Argument Deduction
    Myclass<int> x(12);
    Myclass x2(12); // gecerli/ synax error YOK! C++11/ int oldugunu anladi
    pair p{23, 5.6}; // gecerli
    vector x4 {1, 2, 4, 5}; // gecerli
    tuple t{12, 4.5, 24L, 'X'}; // cok iyi



    return 0;
}

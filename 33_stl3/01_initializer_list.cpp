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

void func(std::initializer_list<int> x){}

struct Nec {
    char a[1024];
};


template <typename T>
void foo(T t){

}

int main(int argc, char const *argv[])
{   
    

    // copy maliyeti dusuk. sadece basini sonunu gosteren pointer verileri kopyalanir
    std::initializer_list <double> x {1.1, 2.2, 3.3, 4.4, 5.5}; 
    cout << "sizeof(x) : " << sizeof(x) << "\n"; // 16 byte

    // kopyalanan sadece pointer degerleri. 
    auto kl = {1,2,3};
    auto lk = kl; 
    cout << (kl.begin() == lk.begin()) << '\n';

    initializer_list<Nec> xx {Nec{}, Nec{}, Nec{}};
    cout << "sizeof(xx) : " << sizeof(xx) << "\n"; // 16 byte.

    // initializer list tipinde bir nesne nasil olusturulur
    auto y = {1, 3, 4, 6};
    auto t = {'a', 'b'};

    auto a {12}; // DIKKAT! Burada initializer_list olmaz! int olur. 
    // auto b { 12, 12}; // DIKKAT! Burada initializer_list olmaz! SE

    auto k = 12;
    auto l = k;
    foo(k);

    foo(y);
    // foo({1, 3, 4, 6}); //  SE Template argument deduction'da initializer_list kullanilamiyor. Ama auto'da cikariliyor. istisna!

    auto list = {1, 3,4,5,6};
    // SADECE 3 member function'i var.
    // list.begin()
    // list.end()
    // x.size()

    // range kullanilabilir
    vector<int> ivec;
    auto ilist = { 3, 4, 5, 6, 7};
    copy(ilist.begin(), ilist.end(), back_inserter(ivec));
     
    // initializer_list elemanlari READ ONLY!!!!!!
    auto fiter = ilist.begin();
    // *fiter = 12; // SE assignment of read-only location '* fiter

    // range based loop can be used
    for (auto a : {k, l, 3, 4, 6}){
        foo(a);
    }

    


    return 0;
}

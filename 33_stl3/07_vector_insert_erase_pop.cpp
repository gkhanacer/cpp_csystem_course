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
    // EKLEME VE SILME ISLEMLERI
    // Vectorun size'ini degistiren fonsiyonlar (ekleme ve silme)
    
    // RESIZE
    vector<int> x {1,2,3,3,4};
    x.resize(20); // sonuna elemanlar eklenecek. value init edilecek. 
    // string "" degerle. int is 0, pointer ise nullptr olacak. sinif icin default ctor.
    cout << x.size() <<   "\n";
    print(x);

    x.resize(15, 100); // resize ile default parameter verilabilir. burada yeni elemanlarin degerleri 100 olacask
    print(x);

    x.resize(4); // daha kucuk bir eleman verilirse, sondaki elemanlar silinir.
    print(x);



    // CLEAR
    x.clear(); // tum elemanlari siler 
    // x.resize(0); // ayni islem
    cout << x.size() <<   "\n";
    print(x);


    //POP_BACK
    // geri donus turu yok!!!
    vector<string> svec{"ali", "veli", "ayse", "fatma", "ali", "veli", "ayse", "fatma"};
    while(!svec.empty()) {
        print(svec);
        // (void) getchar();
        svec.pop_back();
    }

    // ERASE
    // iterator olarak parametre alir.
    vector<string> svec2{"ali", "veli", "ayse", "fatma", "ali", "veli", "ayse", "fatma"};
    // ilk ornegi sil
    svec2.erase(svec2.begin());
    print(svec2);
    // son ornegi sil
    // svec2.erase(svec2.end() - 1);
    svec2.erase(std::prev(svec2.end()));
    print(svec2);

    // verilen degere sahir ilk ogeyi sil
    string name {"ayse"};
    if(auto iter = find(svec2.begin(), svec2.end(), name); iter != svec2.end()) {
        svec2.erase(iter);
    }
    print(svec2);

    // COK ONEMLI!!!!
    // container'larin erase islevleri iterator dondurur. silinen ogeden sonrakini dondurur.
    vector<string> svec3{"ali", "veli", "ayse", "fatma", "ali", "veli", "ayse", "fatma"};
    auto iter = svec3.erase(svec3.begin() + 3); // fatma silinir
    print(svec3);
    cout << *iter << '\n'; // ali yazar

    // range'deki ogeleri sil
    iter = svec3.erase(svec3.begin() + 3, svec3.begin() + 5); // gecersiz range kontrol edilmiyor. UB olurdu
    print(svec3);
    cout << *iter << '\n'; //


    // PUSH_BACK
    // lvalue gonderirse ekleme kopyalama yoluyla olur
    // pr valur gonderirsen tasima yoluyorla eklenir
    vector<string> ivalue;
    string n{"kale"};
    // ivalue.push_back(n);
    // ivalue.push_back(std::move(n));

    ivalue.insert(ivalue.begin(), "baba"); // basa ekler
    ivalue.insert(ivalue.end(), "deli"); // en sona ekler
    ivalue.insert(ivalue.begin()+1, "eli");
    print(ivalue);
    return 0;
}

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


int main(int argc, char const *argv[])
{   
    vector<int> x; // default ctor
    vector<int> x2 {1, 2, 3}; // initializer_list ctor
    vector<int> x3(12); // size_t ctor. n tane elemani value init ederek vectoru olusturur.
    print(x3);
    vector<int*> x4(10); // nullptr ile initialize edilen 10 elemanli vector
    print(x4);
    vector<int> x5(40, 5); // fill. (size_t n, val) n tane val ile vectoru olusturur
    print(x5);
    
    vector<string> vec1 = {"ale", "lager", "weiz"};
    auto vec2 = vec1; // copy ctor cagirilir. 
    auto vec3 = std::move(vec1); //move ctor
    print(vec1);
    cout<< vec1.size() << "\n"; // vectorun ogeleri tasindi ama vector hala hayatta. 
    // (ama akibeti belli degil. MOVED-FROM-STATE. durumu derleyiciye bagli. cogu dernleyici default init ediyor)
    // tekrar tekrar kullanilabilir
    print(vec2);
    print(vec3);

    // vectorun kendisinin tasinmasiyla elemanlarinin tasinmasi farkli seyler. DIKKAT!
    vector<string> vec4;
    for(int i = 0; i < vec2.size(); ++i) {
        vec4.push_back(std::move(vec2[i]));
    }
    print(vec2); // elemanlari tasindi ama size ayni kaldi
    cout<< vec2.size() << "\n";
    print(vec4);

    string str;
    vector<string> svec;
    while(std::cin >> str) {
        //svec.push_back(str); // gecerli ama her seferinde copy yapiyor.
        svec.push_back(std::move(str)); // str tasindi. ama tekrar tekrar kullanillabilir.
    }

    return 0;
}

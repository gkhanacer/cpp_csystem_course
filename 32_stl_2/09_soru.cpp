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

// uzunlugu n olanlari kopyala
int main(int argc, char const *argv[])
{
    vector<string> svec {"ankara", "istanbul", "izmir", "antalya", "yozgat", "tunceli", "aydin"};
    list<string> slist;
    print(slist);

    int len;
    cout << "uzunluk giriniz : ";
    cin >> len;

    copy_if(svec.begin(), svec.end(), back_inserter(slist), [len](const string& s){
        return s.length() == len;
    });

    print(slist);  
    return 0;
}

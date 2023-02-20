#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <set>

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


// bir vectorde tutulan verilen degerlerden en sonuncusunu sil
int main(int argc, char const *argv[])
{
    int ival;
    cout << "tam sayi girin giriniz : ";
    cin >> ival;

    vector<int> ivec{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6};
    print(ivec);

    // erase'e hangi konumu verirsek onu siler
    if (auto iter = find(ivec.rbegin(), ivec.rend(), ival); iter != ivec.rend()) {
        ivec.erase(iter.base() - 1); //erase riter kabul etmez.
    } else {
        cout << "bulunamadi\n";
    }
    print(ivec);

    return 0;
}

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

int main(int argc, char const *argv[])
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 2, 2, 3};
    print(ivec);

    int ival;
    cout << "tam sayi girin giriniz : ";
    cin >> ival;

    cout << count(ivec.begin(), ivec.end(), ival) << "\n";

    cout << count_if(ivec.begin(), ivec.end(), [](int x) {
        return x % 2 == 0;
    }) << "\n";

    int n;
    cout << "kaca tam bolunenlersayilsin : ";
    cin >> n;
    cout << count_if(ivec.begin(), ivec.end(), [n](int x) {
        return x % n == 0;
    }) << "\n";

    return 0;
}


#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
using namespace std;

template <typename InIter>
void print(InIter beg, InIter end) 
{
    while (beg != end) 
    {
        cout << *beg++ << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    vector<int> ivec {1,2,3,4,5,67};
    const vector<int>::iterator iter = ivec.begin();
    // ++iter; // SE
    *iter = 4;

    vector<int>::const_iterator iter2 = ivec.begin();
    ++iter2;
    // *iter2 = 3; // SE

    auto iter3 = ivec.cbegin(); // const iterator
    auto iter4 = ivec.cend();   // const iterator

    // global cbegin ve cend de var
    for (auto  iter = cbegin(ivec); iter != cend(ivec); iter++)
    {
        /* code */
    }
    
    // reverse rbegin, rend
    vector<string> svec {"gokhan", "ahmet", "emre", "ayse" };
    print(svec.rbegin(), svec.rend());
    std::vector<int>::reverse_iterator riter;


    return 0;
}

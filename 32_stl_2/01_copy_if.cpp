
#include<vector>
#include<iostream>
#include <algorithm>
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

template <typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg)
{
    while (beg != end) {
        *destbeg++ = *beg;
    }
    return destbeg;
}

template <typename InIter, typename OutIter, typename Pred> // Pred callable
OutIter CopyIf(InIter beg, InIter end, OutIter destbeg, Pred f) 
{
    while (beg != end)
    {
        if (f(*beg)) {
            *destbeg++ = *beg;
        }
        ++beg;
    }
    return destbeg;
}

// f ne olabilir?
// 1 function pointer 
// 2 sinif turunden nesne (fonsiyon cagri operatorunu overload etmis bir sinif) - functor - function object
// 3 

bool is_len_5(const std::string& s)
{
    return s.length() == 5;
}

int main(int argc, char const *argv[])   
{
    vector <string> svec{"ali", "veli", "gokhan", "ahmet"};
    vector<string> destvec(4);

    // auto iter = CopyIf(svec.begin(), svec.end(), destvec.begin(), &is_len_5);
    auto iter = copy_if(svec.begin(), svec.end(), destvec.begin(), &is_len_5);
    print(destvec);
    return 0;
}

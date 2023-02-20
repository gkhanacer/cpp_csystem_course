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

template <typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg)
{
    while (beg != end) {
        *destbeg++ = *beg++;
    }
    return destbeg;
}

template<typename C>
class BackInsertIterator {
public:
    BackInsertIterator(C& c): mc(c) {}
    BackInsertIterator& operator=(const typename C::value_type& val)
    {
        mc.push_back(val);
        return *this;
    }
    BackInsertIterator& operator*()
    {
        return *this;
    }
    BackInsertIterator& operator++()
    {
        return *this;
    }
    BackInsertIterator& operator++(int)
    {
        return *this;
    }
private:
    C& mc;
}; 

template <typename C>
BackInsertIterator<C> backinserter(C& c)
{
    return BackInsertIterator<C>{c};
}

int main(int argc, char const *argv[])
{
    vector<int> ivec {1 ,2, 3, 4, 5, 7, 8, 9};
    vector<int> x;

    // copy(ivec.begin(), ivec.end(), back_inserter(x));
    // Copy(ivec.begin(), ivec.end(), BackInsertIterator<vector<int>>(x));
    Copy(ivec.begin(), ivec.end(), backinserter(x));
    print(x);

    return 0;
}


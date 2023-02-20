
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

// FUNCTOR CLASS
class LenPred {
public:
    LenPred(std::size_t len) : m_len{len}{}
    bool operator()(const string& s) const
    {
        return s.length() == m_len;
    }
private:
    std::size_t m_len;
};

// FUNCTOR CLASS (Lambda expression bu sinifi bizim yerimize yaziyor :D )
class CharPred {
public:
    CharPred(char c) : m_c{c} {}
    bool operator()(const string& s) const
    {
        return s.find(m_c) != std::string::npos;
    }
private:
    char m_c;
};

int main(int argc, char const *argv[])   
{
    vector <string> svec{"ali", "veli", "gokhan", "ahmet"};
    vector<string> destvec(4);

    // auto iter = copy_if(svec.begin(), svec.end(), destvec.begin(), LenPred{4});
    auto iter = copy_if(svec.begin(), svec.end(), destvec.begin(), CharPred{'a'});
    print(destvec);
    return 0;
}

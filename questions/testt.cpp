#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

template <typename T>
struct B {
    virtual ~B() noexcept
    {
        cleanup();
    }
    virtual void cleanup() = 0;
};

struct D : public B<D>
{
    void cleanup(){

    }
};
int inc(int& x) {
    std::cout << ++x;
    return x;
}
int main(int argc, char const *argv[])
{
    std::vector<int> test {1,2,3};
    auto iter = test.begin();
    auto prev = iter;
    ++iter;
    cout << (iter==prev) << '\n';
    test.erase(prev);

    for(auto n : test) {
        cout << (n) << '\n';
    }
    
    // int a = 0;
    // cout << sizeof("");
    return 0;
}

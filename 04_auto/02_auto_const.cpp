#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int x = 120;

    const auto y = x;

    static auto z = x;

    auto p = &x;
    auto *pp = &x;

    const auto p2 = &x;
    auto const p3 = &x;

    auto &r = 10; // syntax error: l-val'e r val atanıyor
    
    return 0;
}

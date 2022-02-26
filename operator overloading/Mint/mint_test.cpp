#include "mint.h"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    using namespace std;

    Mint x{ 245 }, y{ 8673 }, t{ 85 }, z{};

    std::cout << x << " " << y;

    std::cout << Mint{123} * Mint{234} + Mint{4};

    auto r = Mint::random_mint();
    cout << "r: " << r << "\n";
    
    std::cout << "iki deger girin: ";
    std::cin >> x >> y;
    //operator<<(operator<<(operator<<(std::cout, m1), " "), m2);

    ofstream ofs{"deneme.txt"};
    for(int i=0; i < 10; ++i) {
        ofs << Mint{i} << "\n";
    }
    x = y * z + t;
    if (x > y)
        std::cout << x << " > " << y << "\n";

    ++x;
    y--;
    return 0;
}

#include <iostream>
#include <string>

constexpr bool isprime (int x)
{
    if (x == 0 || x == 1) return false;
    if (x % 2 == 0) return x == 2;
    if (x % 3 == 0) return x == 3;
    if (x % 5 == 0) return x == 5;

    for (int i = 7; i*i <= x; i+2) 
    {
        if (x % i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    constexpr int x = 12312421, y = 233242;
    constexpr auto b = isprime(x - y + 1);
    auto g = isprime(x - y + 1);

    if (b) {
        constexpr int a = 5;
    }
    return 0;
}

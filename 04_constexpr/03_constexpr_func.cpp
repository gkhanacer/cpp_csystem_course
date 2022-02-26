#include <iostream>

constexpr int func(int x, int y)
{
    // static int z = 10;
    return x*x + y*y;
}

int main(int argc, char const *argv[])
{
    const auto x = func(10, 20);

    int a[func(10,20)] {};
    
    return 0;
}

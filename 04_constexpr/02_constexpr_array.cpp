#include <iostream>

int main(int argc, char const *argv[])
{
    constexpr int a[] = {1,2,3,4,5};
    constexpr int x = a[2];
    // constexpr int y = a[7];

    constexpr auto b = 10 > 5;

    const int y = 40;
    const int j = 20;
    constexpr int e = y + j;
    
    constexpr int z = 4;
    constexpr auto k = y + z;
    return 0;
}

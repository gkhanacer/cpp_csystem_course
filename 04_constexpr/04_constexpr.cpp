#include <iostream>

constexpr int func(int x, int y)
{
    // static int z = 10;
    return x*x + y*y;
}

constexpr int foo(std::string x) // HATA: Non-Literay type: string
{
    // static int z = 10;
    return 1;
}


int main(int argc, char const *argv[])
{

    constexpr int a = 7;
    const int b = 5;
    constexpr auto val = func(a * a, b+13);

    int c = 6;
    int d = 4;
    
    int arr[func(c, d)]; // Syntax Error

    constexpr int g = func(c, c + 21); // Syntax Error
    int h = func(c, c + 21); // Geçerli

    return 0;
}

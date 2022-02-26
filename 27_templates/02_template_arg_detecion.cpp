#include <iostream>

template <typename T>
void func(T x)
{
    
}

template <typename T>
void bar(T x)
{
    ++x;
    std::cout << x << "\n";
}

int main(int argc, char const *argv[])
{
    // func(12);
    // bar(12);
    bar(true); // error! Second control. Real sentax control
    return 0;
}

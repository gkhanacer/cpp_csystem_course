#include <iostream>

// template <typename T>
// void func(T x)
// {
//     foo(); // Pure template control (first control) at compile time. (namespace control will be done at this stage.)
// }

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

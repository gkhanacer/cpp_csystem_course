#include <iostream>
#include <string>

// partial ordering rules: daha specific olan seçilir!
template <typename T>
void func(T &)
{
    std::cout << "1" << '\n';
}

template <typename T>
void func(T (&)[10])
{
    std::cout << "2" << '\n';
}

int main(int argc, char const *argv[])
{

    int a[10]{};
    func(a); // 2

    return 0;
}

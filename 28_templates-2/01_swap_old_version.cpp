#include <iostream>

template <typename T>
void Swap(T &x, T &y)
{
    T temp{x};
    x = y;
    y = temp; 
}

int main(int argc, char const *argv[])
{
    int a{3}, b{7};
    Swap(a, b);
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    double d1 {3.23423}, d2 {5.43534};
    Swap(d1, d2);
    std::cout << "d1 = " << d1 << "\n";
    std::cout << "d2 = " << d2 << "\n";

    std::string s1{"muzaffer"}, s2 {"ferhunde"};
    Swap(s1, s2);
    std::cout << "s1 = " << s1 << "\n";
    std::cout << "s2 = " << s2 << "\n";

    return 0;
}

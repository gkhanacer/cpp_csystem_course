#include <iostream>

template <typename T>
void Swap(T &x, T &y)
{
    // move constructor kullanılır. Performans artar.
    T temp{std::move(x)}; // l-value to r-value. x'in kaynağı çalındı.
    x = std::move(y); // kaynağı çalınmış nesne, kullanılabilir bir nesnedir. x tekrar kullanılabilir! Değerinin ne olduğu konusunda bir garanti yok.
    y = std::move(temp);
}

int main(int argc, char const *argv[])
{
    int a{3}, b{7};
    Swap(a, b);
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    double d1{3.23423}, d2{5.43534};
    Swap(d1, d2);
    std::cout << "d1 = " << d1 << "\n";
    std::cout << "d2 = " << d2 << "\n"; 

    std::string s1{"muzaffer"}, s2{"ferhunde"};
    Swap(s1, s2);
    std::cout << "s1 = " << s1 << "\n";
    std::cout << "s2 = " << s2 << "\n";

    return 0;
}

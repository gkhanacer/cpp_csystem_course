#include <iostream>
#include <string>

template <typename T>
void func (T x) 
{
    std::cout << "function template type T is : " << typeid(T).name() << '\n';
}

// void func(double)
// {
//     std::cout << "function(double)" << '\n';
// }

// Kural: eğer argümanla parametre deişkeni tam uyumluysa gerçek fonksiyon kullanılır.
void func(int)
{
    std::cout << "function(int)" << '\n';
}

int main(int argc, char const *argv[])
{
    func(10);
    func('a');
    return 0;
}

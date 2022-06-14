#include <iostream>

// Öyle bir fonksiyon oluştur ki bu fonksiyonun parametresi neyse sadece o türden argümanla çağrılabilsin.

// Burayı ekliyoruz
template <typename T>
void func(T x) = delete;
 
void func(int){
    std::cout << "func(int)\n";
}

int main(int argc, char const *argv[])
{
    func(1);
    func('a'); // char ile func(int) fonksiyonu çağrılabiliyor. bunu istemiyoruz.
    return 0;
}
 
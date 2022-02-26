#include <iostream>

// Yalnızca burası yazılsa, sentax hatası olmaz. 
// Ama F türünün ne olduğu belli olduğunda, bu kodun geçerli olabilmesi için
//- f'nin fonksiyon çağrı operatorünün operandı olabilecek bir türde olması gerekir:
// a. F bir function pointer olabilir.
// b. F bir sınıf türü olabilir. bu sınıf için function call operator fonksiyonu overload edilmiş olabilir.
template <typename F> 
int func(F f) 
{
    return f(12);
}

// a. F bir function pointer olabilir.
int foo(int x)
{
    std::cout << "foo çağrıldı\n";
    return x*x;
}

// b. F bir sınıf türü olabilir. bu sınıf için function call operator fonksiyonu overload edilmiş olabilir.
class Myclass
{
public:
    int operator()(int x)const
    {
        std::cout << "Myclass::operator()(int)\n";
        return x+5;
    }

};

int main(int argc, char const *argv[])
{
    func(foo);

    auto x =  func(Myclass{});

    return 0;
}


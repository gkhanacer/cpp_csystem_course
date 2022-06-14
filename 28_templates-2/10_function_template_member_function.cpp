#include <iostream>

class Myclass
{
public:
    template <typename T>
    Myclass(T x) {}
    // void func(int x) const
    // {
    //     std::cout << "Myclass::func(int)\n";
    // }

    // void func(double x) const
    // {
    //     std::cout << "Myclass::func(double)\n";
    // }

    // void func(long x) const
    // {
    //     std::cout << "Myclass::func(long)\n";
    // }

    template <typename T>
    void func(T x)
    {
        std::cout << "type T is: " << typeid(T).name() << "\n";
    }
};

int main(int argc, char const *argv[])
{
    Myclass m{24}; 
    Myclass m2{2.4};
    Myclass m3{2L};
    Myclass m4{'a'};
    Myclass m5{"gokhan"}; 

    m.func(10);
    m.func(1.20);
    m.func(123L);
    m.func('A');
    return 0;
}

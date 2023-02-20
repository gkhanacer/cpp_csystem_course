#include <iostream>

class Myclass {
public:
    Myclass()
    {
        std::cout << "defatult ctor this = " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "dtor this = " << this << "\n";
    }

    Myclass(const Myclass& r)
    {
        std::cout << "cc this = " << this  << " , &r = " << &r << "\n";
    }
};

// call-by-value
void foo(Myclass m) {
    std::cout << "foo cagirildi" << "\n";
}

Myclass func() {
    Myclass m;
    return m;
}

int main(int argc, char const *argv[])
{
    Myclass m1;

    Myclass m2 = m1;
}

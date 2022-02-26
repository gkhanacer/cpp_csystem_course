#include <iostream>

class Base {
protected:
    void func(int) {
        std::cout << "func(int)\n";
    }
};

class Der : public Base {
public:
    void func(double) {
        std::cout << "func(double)\n";
    }
};

int main(int argc, char const *argv[])
{
    Der myder;

    myder.func(2); // Der::func(double) çağrılır. Burada function overloading yok.

    return 0;
}

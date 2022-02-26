#include <iostream>

class Base {
protected:
    void func(int) {
        std::cout << "func(int)\n";
    }
};

class Der : public Base {
public:
    using Base::func; // Base::func Der sınıfının public interface'ine inject edilir
    void func(double) {
        std::cout << "func(double)\n";
    }
};

int main(int argc, char const *argv[])
{
    Der myder;

    myder.func(2); // Der::func(int) çağrılır. Burada function overloading var.

    return 0;
}

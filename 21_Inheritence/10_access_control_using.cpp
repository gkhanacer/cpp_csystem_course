#include <iostream>

class Base {
protected:
    void func(int) {

    }
};

class Der : public Base {
public:
    using Base::func; // Base sınıfının func fonksiyonu artık visible. Inject edildi.
};

int main(int argc, char const *argv[])
{
    Der myder;

    myder.func(2); 

    return 0;
}

#include <iostream>


// NOT: Burada overloading yok. Aynı scope'ta değiller.
// İşlem sırası: 1. namelookup, 2. context control, 3. access control
// Namelookup Der içinde foo'yu bulur, isim arama biter. Diğer kontroller başlar: context, access control.
class Base {
public: 
    void foo() {
        std::cout << "Base::foo()\n";
    }
};

class Der : Base {
public:
    void foo() {
        std::cout << "Der::foo()\n";
    }
};

int main(int argc, char const *argv[])
{
    Der myder;
    myder.foo();
    return 0;
}

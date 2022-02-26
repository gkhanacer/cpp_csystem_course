#include <iostream>


/**
 * Türemiş sınıfın üye fonksiyonu içinde nitelenmeden kullanılan isim:
 * 1. önce bulunduğu blok içinde, bulunmazsa
 * 2. sonra kapsayan sınıf içinde, bulunmazsa
 * 3. sonra Türemiş sınıfın scope'u içinde, bulunmazsa,
 * 4. sonra Taban sınıfın scope'u içinde, bulunmasa,
 * 5. Global scope'ta
 * arar.
 * 
 */

int x = 20;

class Base {
public: 
    void foo(int a, int b) {
        std::cout << "Base::foo(int, int)\n";
    }

    int x = 10;

};

class Der : public Base {
public:
    void foo(double) {
        std::cout << "Der::foo(double)\n";
    }

    void func() {
        x = 4;

        std::cout << x << '\n'; // local x
        std::cout << this->x << '\n'; // Der::x
        std::cout << Der::x << '\n'; // Der::x
        std::cout << Base::x << '\n'; // Base::x
        std::cout << ::x << '\n'; // ::x global (namespace scope)
    }
};

int main(int argc, char const *argv[])
{
    Der myder;
    // myder.foo(12, 13); // Syntax error! foo'yu türemiş sınıf içinde bulur, isim arama biter. context control'de uygun foo(int, int) fonksiyonunu bulamaz.
    myder.Base::foo(12, 13); // Bu şekilde name hidding aşılmış olur.

    myder.func(); // x, önce türemiş sınıf içinde aranır. Bulunamaz. Base sınıf içinde arar.
    std::cout << myder.x << '\n';

    return 0;
}

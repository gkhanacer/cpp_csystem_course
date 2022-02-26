#include <iostream>

/**
 * Bir sanal fonksiyonu override etmek için türemiş sınıfın
 *  - hem geri dönüş türü aynı,
 *  - hem de imzası aynı
 * bir fonksiyon bildirmesi gerekir. 
 * 
 * 
 * Taban sınıfın bir sanal fonksiyonuyla aynı isimli aynı imzaya sahip fakat
 * geri dönüş türü farklı bir fonksiyon bildirmek sentaks hatasıdır.
 */
class Base {
public:
    virtual void func() // virtual kw yalnızca bildirimde kullanılır.
    {
        std::cout << "Base::func()\n";
    }

    void func(int, int)
    {
        std::cout << "Base::func(int, int)\n";
    }
};

class Der : public Base {
public:
    void func()
    {

    }

    void func(int) // Syntax Error yok, ama override da yok!
    {

    }

    // Syntax Error! virtual function override edilmek istenmiş. Ama geri dönüş türü yanlış
    // Eğer Base::func(int, int) fonksiyonu virtual olmasaydı, hata olmazdı. Çünkü scope'lar farklı. Overloading de yok.
    // Ama virtual kw kullanıldığı için artık durum çok farklı.
    int func(int, int) 
    {

    }
};
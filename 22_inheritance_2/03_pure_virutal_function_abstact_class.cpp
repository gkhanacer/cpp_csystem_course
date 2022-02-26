
// interface verir implementation vermez!
// Pure Virtual Functin içerir. 
// Eğer bir sınıfın En az bir pure virtual function varsa, Bu sınıflara Abstract Class denir, ve bunlardan instance oluşturulamaz (Syntax Error).
// Concrete class: Nesne oluşturulabilen sınıflar.
// Türeyen sınıflar pure virutal function'ları override edip implement etmek ZORUNDA!
// Override etmezse yaptırımları var.
// NOT: Abstract sınıfın constructor'u veya destructor'u olabilir!!!
class Airplane 
{
public:
    void fly(); 
    virtual void takeoff();
    virtual void land() = 0; // Pure Virtual Function

};

// Eğer abstact bir sınıftan (Airplane) türeyen sınıf, abstract sınıfın tüm pure virtual function'larını override etmezse,
// türeyen sınıf da (Boeing) Abstact sınıf olur.
class Boeing : public Airplane
{

};

class Nec {
    public:
        virtual void func() = 0;
};


// Abstact bir sınıftan nesne oluşturulamaz, ama Pointer veya Referance oluşturulabilir.
// Örneğin bir Fonksiyonun parameteresi olabilirler.
void foo(Nec* p);
void func(Nec& r);

int main(int argc, char const *argv[])
{
    // Nec nec; // Syntax Error! Nec bir sanal sınıf.
    // Airplane a; // Syntax Error! Airplane bir sanal sınıf.
    // Boeing b;    // Syntax Error! Boening sınıfı, Airplane sınıfından türemiştir. Airplane sınıfının tüm pure virtual function'larını override etmemiştir.
                    // Bu durumda Boeing sınıfı da abstract bir sınıftır ve ondan nesne oluşturulamaz.

    return 0;
}


// interface + default implementation var.
// Bu örüntü virtual kw ile gerçekleştirilir.
// virtual kw ile tanımlanan fonksiyonua virtual function (sanal fonksiyon) denir.
// En az 1 virtual fonktion olan sınıfa: POLYMORHIC CLASS nedir.
// Türeyen sınıflar ister bu virtual function'ı override eder, isterse doğrudan kabul ederek kullanırlar.
// Türeyen sınıflar virtual function'ı override etmek zorunda DEĞİL!
class Airplane 
{
public:
    void fly(); 
    virtual void takeoff();
};

class Boeing : public Airplane
{

};
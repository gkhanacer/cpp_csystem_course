
// interface + implementation var.
class Airplane 
{
public:
    void fly(); // Taban sınıfın bu koduna dokunma! Türeyen sınıflar bunu kullanır!
};

class Boeing : public Airplane
{

};
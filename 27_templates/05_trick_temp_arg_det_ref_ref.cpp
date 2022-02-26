template <typename T>
class TypeTeller;

template <typename T>
void func(T &&) // forwarding (universal) referance 
{
    TypeTeller<T> y;
}

int foo(int x)
{
    return x*x;
}

int main(int argc, char const *argv[])
{
    
    // r-value: bu durumda türün kendisi olur
    func(12); // T: int, function param: int&&

    // l-value: bu durumda T l-value referance olur
    int x = 10;
    func(x); // T: int&, param: int &


    return 0;
}

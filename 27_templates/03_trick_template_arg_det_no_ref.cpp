template <typename T>
class TypeTeller;

template <typename T>
void func(T)
{
    TypeTeller<T> y;
}

int foo(int x)
{
    return x*x;
}

int main(int argc, char const *argv[])
{
    // Doğrudan türün kendisini alır
    // func(10); // T: int 

    // const'luk düşer! T: int
    // const int x = 10; 
    // func(x);

    // ref düşer
    // int z = 10; 
    // int& r = z;
    // func(r); // T: int 

    // array decay
    // int a[5]{}; 
    // func(a);// T: int *

    // function pointer
    // func(foo); // T: int(*)(int)

    // string literal
    func("ali"); // T: const char*
    
    return 0;
}

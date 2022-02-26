template <typename T>
class TypeTeller;

template <typename T>
void func(T &)
{
    TypeTeller<T> y;
}

int foo(int x)
{
    return x*x;
}

int main(int argc, char const *argv[])
{
    
    int x = 4;
    func(x); // T: int, function param: int&

    // const'luk düşmez
    const int y = 34;
    func(y); // T: const int, function param: const int&

    // array decay olmaz
    int a[5]{};
    func(a); // T: int[5] , function param: int(&)[5]

    func("ali"); // T: const char[5] , function param: const char(&)[4]

    func(foo); // T: int(int) , function param: int(&)(int)


    return 0;
}

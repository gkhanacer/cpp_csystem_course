template <typename T, int size>
void func(T(&)[size])
{
}

template <typename T>
void foo(T &)
{
}

int main(int argc, char const *argv[])
{
    int a[5]{};

    foo(a); // T: int[5] (foo'da & var, array decay olmaz!)

    func(a); // T: int ve size: 5 olur!
    
    return 0;
}




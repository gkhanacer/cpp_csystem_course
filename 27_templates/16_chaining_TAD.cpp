template <typename T>
void foo(T y)
{
    
}

template <typename T>
void func(T x)
{
    foo(&x); // 2. foo için T: int *, y: int *
}

int main(int argc, char const *argv[])
{
    func(10); // 1. func için T: int olur, x: int 
    return 0;
}

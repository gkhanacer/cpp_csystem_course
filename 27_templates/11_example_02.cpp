template <typename T>
void func(T x)
{
}

template <typename T>
void foo(T *x)
{
}

template <typename T>
void bar(T **x)
{
}

int main(int argc, char const *argv[])
{
    int x = 10;
    int *p = &x;
    int **ptr = &p;

    func(ptr); // T: int**, x: int**
    foo(ptr); // T: int*, x: int**
    bar(ptr); // T: int, x: int**
    return 0;
}

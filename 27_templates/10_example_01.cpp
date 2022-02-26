template <typename T>
void func(T x);

template <typename T>
void foo(T *x);

int main(int argc, char const *argv[])
{
    int ival{};

    func(&ival); // T: int*, x: int*
    auto p = &ival; // auto: int*, p: int* 

    foo(&ival); // T: int, x: int*
    auto *ptr = &ival; // auto int, ptr: int*

    return 0;
}

// auto için yapılan tür çıkarımı ile Template Argument Deduction arasında bir fark yok.
// bir istisna var: initializer list

template <typename T>
void func(T x);

int main(int argc, char const *argv[])
{
    auto x {1,2,3,4,5,6}; // x: std::initializer_list<int>

    func({1,2,3,4,5,6}); // Syntax error! x
    return 0;
}

template <typename T>
T foo()
{
}

template <typename T>
void func(T x, T y)
{
}

int main(int argc, char const *argv[])
{
    // foo(); // T türü için çıkarım yapamaz!

    // int x =  foo(); // T türü bu şekilde de çıkarılamaz!

    // func(10, 20); // Bu çalışır! T için her iki tür için de int olarak çıkarım yapılır.
    // func(10, 2.0); // Syntax Error! T içn hem int hem double çıkarımı yapılıyor. Ambiguity

    func<int>(10, 2.0); // Bu çalışıyor! Burada explicit argument type belirleniyor. Template Argument Deduction DEVRE DIŞI KALIR!!!!
    // Burada narrowing conversion olur

    return 0;
}

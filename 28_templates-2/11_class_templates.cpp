#include <iostream>

template <typename T>
class Myclass {
public:
    T& func(T x);
private:
    T mx;
};

template <typename T>
T& Myclass<T>::func(T x)
{
    std::cout << "Myclass<T>::func(T x)   type: " << typeid(T).name() << "\n";
}

int main(int argc, char const *argv[])
{
    // Myclass m1; // syntax error

    Myclass<int> mi;
    Myclass<double> md;
    // mi = md; // syntax error

    mi.func(10);
    mi.func(1.0); // narrowing

    md.func(1.2);
    md.func(10); // int to double cast
    // md.func("gokhan"); // syntax error! T: double tanımlandı. 

    return 0;
}

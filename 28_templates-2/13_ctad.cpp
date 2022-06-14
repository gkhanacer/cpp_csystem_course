template <typename T>
class Nec {
public:
    Nec func(Nec);
    //Nec<T> func(Nec<T>) // bu şekilde de tanımlanabililrdi.

    Nec foo();
};

template <typename T>
Nec<T> Nec<T>::func(Nec)
{
    Nec x;
}

template <typename T>
Nec<T> Nec<T>::foo()
{
    return *this;
}


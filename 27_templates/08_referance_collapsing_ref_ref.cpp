
template <typename T>
void func(T&&) // forwarding ref
{

}

int main(int argc, char const *argv[])
{
    // Her ikisi de r-val ise, referance collapsing'e göre sonuç zaten r-val, T'nin türü asla REF olmaz. ;)
    auto&& x = 10; // r-val  U  r-val --> r--val, auto: int, x: int&&

    func(10); // r-val  U  r-val --> r--val, T: int, param: int&&


    // Biri r-val, diğeri l-val ise, referans collapsing olur. Sonuç l-val olur. T'nin türü REF olur! ;)
    int ival{6};

    auto&& x = ival; // r-val  U  l-val --> l-val, auto: int&, x: int&

    func(ival); // r-val  U  l-val --> l--val, T: int&, param: int&

    return 0;
}

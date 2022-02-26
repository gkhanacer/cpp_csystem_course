
int main(int argc, char const *argv[])
{
    using mytype = int&;
    // mytype &x; // l-val U  l-val --> x: int& (syntax error: must be initialized.)

    int ival{};
    mytype &x = ival; // l-val U  l-val --> l-val, x: int& 

    return 0;
}

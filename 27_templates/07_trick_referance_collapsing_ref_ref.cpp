
int main(int argc, char const *argv[])
{
    using mytype = int&&;

    int ival{};
    mytype &x = ival; // r-val U  l-val --> l-val, x: int& 

    mytype &&x = 10;  // r-val U  r-val --> r-val, x: int&& 

    return 0;
}

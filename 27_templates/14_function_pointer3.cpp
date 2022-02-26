template <typename T, typename U>
void foo(T(*)(U))
{

}

int func(double)
{
    
}

int main(int argc, char const *argv[])
{
    foo(func); // T: int, U: double

    return 0;
}

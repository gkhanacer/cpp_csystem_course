
void foo(int(*)(double))
{

}

int func(double)
{
    
}

int main(int argc, char const *argv[])
{
    foo(&func);

    return 0;
}

template <typename T>
class TypeTeller;

template <typename T>
void func(T)
{
    TypeTeller<T> y;
}

int main(int argc, char const *argv[])
{
    // func(10); // int 

    const int x = 10; // const'luk düşer! int
    func(x);
    
    return 0;
}

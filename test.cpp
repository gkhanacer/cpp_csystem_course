#include <iostream>

class Myclass
{
public:
    Myclass()=default;
    Myclass(const Myclass& other) = delete;
    Myclass& operator=(const Myclass &other) = delete;
};

int main(int argc, char const *argv[])
{
    Myclass m1, m2;

    m1 = m2;
    Myclass m3{m1};

    return 0;
}

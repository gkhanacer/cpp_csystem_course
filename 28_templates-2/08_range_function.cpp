#include <iostream>

void func(int *pbeg, int *pend)
{
    while (pbeg != pend)
    {
        std::cout << *pbeg++ << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int a[5] = {0, 1, 2, 3, 4};
    func(a, a + 5);
    return 0;
}

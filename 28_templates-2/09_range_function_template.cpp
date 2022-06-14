#include <iostream>
#include <vector>
#include <list>
 
template <typename Iter>
void Print(Iter beg, Iter end) 
{
    while (beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << "\n";
}

int main(int argc, char const *argv[])
{
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    Print(a, a + 7);
    Print(a, a + 3);
    Print(a + 4, a + 7);

    double da[] = {1.1, 2.2, 3.3, 4.4};
    Print(da, da + 4);

    std::vector<int> ivec {10, 20, 30, 40, 50};
    Print(ivec.begin(), ivec.end());

    std::list<int> ilist {10, 20, 30, 40, 50};
    Print(ilist.begin(), ilist.end());

    return 0;
}

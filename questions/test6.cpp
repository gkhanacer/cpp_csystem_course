#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;


int main(int argc, char const *argv[])
{
    int i = 7;
    char c = 'a';

    [=, &i]() mutable 
    {
        i++;
        c = 'b';
        cout << i << " " << c << '\n';
    }();

    cout << i << " " << c << '\n';
    return 0;
}

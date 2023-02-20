#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

int getLenght() {
    return 10;
}
int main(int argc, char const *argv[])
{
    int x = getLenght();
    char message[x];
    message[0] = 'a';

    int a, b;
    a = 10.0;
    b = 3.0;
    float q = a / b;
    cout << q;

    for (char id = 0; id < 250; id++) // -128, 127
        cout<<"a";
    

    return 0;
}

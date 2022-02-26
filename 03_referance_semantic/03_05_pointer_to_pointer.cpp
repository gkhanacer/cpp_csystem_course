#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int x = 10;
    
    // Pointer to pointer vardır. (hem c hem c++ ta)
    int* p1{ &x };
    int** ptr { &p1 }; 

    // Reference to reference yoktur. r2 de x'in yerine geçen bir referanstır.
    int& r1{ x };
    int& r2{ r1 };
    int& r3{ r2 };

    ++r1;
    ++r2;
    ++r3;
    cout << x << endl;
    return 0;
}

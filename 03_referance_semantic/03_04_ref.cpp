#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int x = 10;
    int* p{ &x };
    int* &r{ p }; // pointer'ın referansı. & r'nin reference olduğunu söylüyor. Hangi türden nesnenin yerine geçecek? -> int*
    
    ++*r; 
    cout << x << endl;
    return 0;
}

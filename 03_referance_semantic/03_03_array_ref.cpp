#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int a[]{1, 2, 3, 4}; 
    int* p = a; // array decay: a dizisinin ilk elemeanının adresi
    int& r1 = a[2]; // a[2] is a l-value expr
    int& r2 = *p; // *p int türünden bir değer



    return 0;
}

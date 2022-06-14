#include <iostream>

using namespace std;

// https://necatiergin2019.medium.com/referanslar-references-1-8770705b8673

int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 45;

    // Top level const
    // Pointer is constant.
    // &: adress operator (address of)
    int* const p = &x; 
    cout << (*p) << endl;

    // Bir referans ilk hangi nesneyi alıyorsa yaşamı boyunca başka bir nesneye bağlanamaz
    // &: declarator
    int& r = x; // Yukarıdakiyle aynı özellikte. Assembly bile aynı.
    cout << r << endl;

    ++r;
    cout << x << endl;
    
    r = y; // x = y demektir. y'nin değerini, x'in değerine kopyalar.
    ++y;
    cout << x << endl;

    return 0;
}

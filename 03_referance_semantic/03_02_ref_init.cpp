#include <iostream>

using namespace std;

// https://necatiergin2019.medium.com/referanslar-references-1-8770705b8673


// references must be initialized
// references cannot be default initialized.
int main(int argc, char const *argv[])
{
    int x = 10;
    // int &k; // reference variable "k" requires an initializer

    // 3  türlü de init edilebilir.
    int& r1{x}; // uniform (brace) init
    int& r2(x); // direct init
    int& r3 = x; // copy init

    // primitive nesneler stack'tedir. Dinamik ömürlü nesneler heap (free store) alanındadır

    int *p = new int; // heap'te
    int& rp = *p; // L value ref'e bir L value ile init ediliyor. rp bir otomatik ömürlü bir değişkendir ve stack'tedir. Ama nesne heap'tedir.

    double dval = 2.30;
    // int& r = dval; // Syntax error.
    // int* p = &dval; // Syntax error.

    unsigned int xx = 10;
    // int& rr = xx; // Syntax error

    // L value ref, r value expr ile ilk değer verilemez!!!!
    // int& r = 10; // 10 bir r value expression. // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’







    return 0;
}

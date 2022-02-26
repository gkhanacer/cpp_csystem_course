#include <iostream>

using namespace std;

int g = 10;  // global variable

int* foo(void) {
    // return
    return &g;
}

// return type: L value reference
int& bar(void) {
    return g;
}

// return type: PR value 
int bar2(void) {
    return g;
}

int* scan_int(void) {
    int x;

    printf("bir tamsayı giriniz");
    scanf("%d", &x); // ub. x otomatik ömürlü bir nesne.  Çünkü bu fonksyionun scope'u bittiğinde x yok olur.

    return &x; // no! no!
}

int main(int argc, char const *argv[]) {
                              
    int* p = foo();
    cout << g << endl;
    // *p = 999;
    *foo() = 999;
    cout << g << endl;

    ++*foo();
    cout << g << endl;

    // int* q = scan_int();
    // cout << *q << endl;

    int x = bar(); // x demek g demek değil çünkü x bir ref değil. copy init.
    int &r = bar(); // FONKSIYON ÇAĞRI İFADESİ BİR L VALUE EXPRESSION
    ++r;
    cout << g << endl;

    // c++ DİLİNDE geri dönüş türü l-val ref olan fonksiyonlara yapılan çağrı ifadeleri l-value-exprs dir.


    return 0;
}

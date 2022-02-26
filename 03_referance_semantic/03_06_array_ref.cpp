#include <iostream>

using namespace std;


int main(int argc, char const *argv[]) {

    int ar[]{2, 5, 6, 9};
    // ar'nin türü: int[4]

    // Pointer to array: ar'nin kendisine bir pointer almak istersek (yalnızca ilk elemanı için değil)
    int (*p)[4] = &ar;
    // *p demek ar demek

    // ref
    // r demek ar demek
    int (&r)[4] = ar;
    r[2] = 34; // ar[2] = 34;

    int* ptr1 = r; // array decay
    int* ptr2 = ar; // array decay

    // autor type deduction
    // int (&rr)[4] = ar;
    auto &rr = ar;


    int at[]{2, 1, 5, 3, 45};
    int (&r)[5] { at };
    int& ir = r[0]; // dizinin ilk elemanının referansı

    return 0;
}

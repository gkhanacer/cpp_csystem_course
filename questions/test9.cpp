#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

void fx(){
    cout<<"x";
}
void fy(){
    cout<<"y";
}
void fz(){
    cout<<"z";
}
typedef void(*PFvv)();
PFvv functions[3] = {fx, fy, fz};

int main(int argc, char const *argv[])
{
    for (int i=0; i < 3; ++i) {
        functions[i]();
    }
    
    return 0;
}

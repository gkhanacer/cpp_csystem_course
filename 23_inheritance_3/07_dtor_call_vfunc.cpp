#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Base {
public:
    ~Base() {
         vfunc();
    }
    virtual void vfunc(){ 
        cout << "base " <<  "\n";
    }
};

class Der: public Base {
public:
    void vfunc() override{ 
        cout << "der " << "\n"; 
    }
};

int main(int argc, char const *argv[])
{
    Der der; // once der nesnesinin dtor'u cagrilir.  sonra base nesnesininki cagirilir.
    return 0;
}

#include <iostream>

class Base {
public: 
    void func(int a, int b) {
        std::cout << "Base::foo(int, int)\n";
    }
};

class Der : public Base {
public:
    void func(double) {
        std::cout << "Der::foo(double)\n";
        //func(12); // recursive call

        //func(12, 12); // Syntax error! İsim arama yapıldı. Der::func ismi bulundu. Context uymadı.
        Base::func(12, 12);
        
    }
};

int main(int argc, char const *argv[])
{
    Der myder;
    myder.func(10);
    return 0;
}

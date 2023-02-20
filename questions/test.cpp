#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class E1 {
public: 
    virtual void printer() { cout << "e1 ";};
};


class E2 : public E1 {
public: 
    void printer() { cout << "e2 ";};
};

int getAge(int id) {
    E1 e1;
    E2 e2;

    if (id == 102) throw(e1);
    else throw(e2);
    return 0;

}
int main(int argc, char const *argv[])
{
    int age;
    for (size_t i = 101; i < 104; i++) {
        try
        {
            age = getAge(i);
        }
        catch(E1& a)
        {
            a.printer();
        }
    }

    return 0;
}

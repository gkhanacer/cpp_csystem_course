#include <iostream>

class Base {

};

class Der : public Base {

};

int main(int argc, char const *argv[])
{
    Der myder;

    Base* baseptr = &myder; // legal
    Base& baseref = myder; // legal

    Base mybase = myder; // DİKKAT! Legal ama kullanma. Object slicing (nesne dilimleme)

    return 0;
}

#include <iostream>
#include <ostream>
#include <memory>

class Nec
{
private:
    int mval{};
public:
    Nec()=default;
    Nec(int x): mval{x} {}
    ~Nec()
    {
        std::cout << "dtor\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Nec& nec)
    {
        std::cout << "{" << nec.mval << "}";
        return os;
    }
    void set(int x)
    {
        mval = x;
    }
};

class NecPtr {
private:
    Nec* mp;

public:
    // unique_ptr'nin primitive hali
    NecPtr(Nec* p) : mp(p) {}
    ~NecPtr()
    {
        delete mp;
    }
    Nec& operator*()
    {
        return *mp;
    }
    Nec* operator->()
    {
        return mp;
    }
};


template <typename T>
class SmartPtr {
public:
    // unique_ptr'nin primitive hali
    SmartPtr(T* p) : mp{p} {}
    ~SmartPtr()
    {
        delete mp;
    }
    T& operator*()
    {
        return *mp;
    }
    T* operator->()
    {
        return mp;
    }
private:
    T* mp;
};

int main(int argc, char const *argv[])
{
    {
        // Nec *pnec = new Nec{1234};
        // pnec->set(3);
        // std::cout << *pnec << "\n";

        // std::unique_ptr<Nec> pnec{new Nec{1234}};
        // pnec->set(3);
        // std::cout << *pnec << "\n";

        // NecPtr pnec { new Nec(1234) };
        // std::cout << *pnec << "\n";
        // // pnec->set(3);
        // pnec.operator->()->set(3);
        // std::cout << *pnec << "\n";

        SmartPtr<Nec> pnec{ new Nec{1234} };
        std::cout << *pnec << "\n";
        // pnec->set(3);
        pnec.operator->()->set(3);
        std::cout << *pnec << "\n";
    }


    std::cout << "main\n";
    return 0;
}


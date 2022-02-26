#include "Sentence.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

Sentence::Sentence(const char *p) : mlen{std::strlen(p)}, mp{static_cast<char *>(std::malloc(mlen + 1))}
{
    if (!mp)
    {
        std::cout << "Bellek yetersiz!\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Sentence::Sentence(const char* p)\n";
    std::cout << "Allocate edilen bellek blogunun adres: " << (void *)mp << "\n";
    std::strcpy(mp, p);
}

Sentence::~Sentence()
{
    std::cout << "~Sentence()\n";
    std::cout << (void *)mp << " adresindeki bellek blogu geri veriliyor\n";
    free(mp);
}

Sentence::Sentence(const Sentence &other) : mlen{other.len()}, mp{static_cast<char *>(std::malloc(mlen + 1))}
{
     if (!mp)
    {
        std::cout << "Bellek yetersiz!\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "cc\n";
    std::cout << "cc cagrildi. Allocate edilen bellek blogunun adres: " << (void *)mp << "\n";
    std::strcpy(mp, other.mp);
}

Sentence &Sentence::operator=(const Sentence& other)
{
    if (this == &other)
        return *this;

    std::cout << "kopyalayan atama operatoru cagirildi\n";
    free(mp); // önce this için kaynak verilir.
    std::cout << (void*)mp  << " adresindeki bellek adresi geri verildi.\n";

    // sonra derin kopyalama yapılır.
    mlen = other.mlen;

    mp = static_cast<char *>(std::malloc(mlen + 1));
    if (!mp)
    {
        std::cout << "Bellek yetersiz!\n";
        exit(EXIT_FAILURE);
    }
    std::cout << "elde edilen bellek blogunun adresi: " << (void*)mp << "\n";
    strcpy(mp, other.mp);

    return *this;
}

void Sentence::print() const
{
    std::cout << "[" << mp << "]\n";
}

std::size_t Sentence::len() const
{
    return mlen;
}
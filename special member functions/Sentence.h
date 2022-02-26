#pragma once

#include <cstddef>

class Sentence {
public:
    Sentence(const char* p); // aldığı adresteki yazının kopyasını tutacak
    ~Sentence();
    Sentence(const Sentence& other);
    Sentence& operator=(const Sentence& other);

    void print() const;
    std::size_t len() const;


private:
    std::size_t mlen;
    char* mp; // heap'te allocate edilecek bellek blogunun adresini tutar.
};
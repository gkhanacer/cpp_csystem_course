#ifndef MINT_H
#define MINT_H

#include <iosfwd> // iostream
#include <stdexcept>
#include <fstream>
#include <ostream>
#include <cstdlib>

// rule of zero

class Mint
{
public:
    explicit Mint(int val = 0) : mval{val} {} // explicit kw ile implicit dönüşümü engelliyoruz. default ctor olması için default arg verilir.

    // Comparision operators
    // equality ve ordering var.
    // Tipik yazım şöyle: < ve == friend yazılır.
    // Diğerleri bu ikisini kullanıyo.
    // friend bool operator<(const Mint &, const Mint &);
    // friend bool operator==(const Mint &, const Mint &);

    // Sign operators
    Mint operator+() const
    {
        return *this;
    }
    Mint operator-() const
    {
        return Mint{-mval};
    }

    // Prefix, postfix
    Mint &operator++() // prefix
    {
        ++mval;
        return *this;
    }
    Mint operator++(int) // postfix (son ek R value expr olması için. ref olsaydı nesnenin eski değerini döndürmesi olamazdı)
    {
        Mint ret{*this};
        // ++*this;
        operator++();
        return ret;
    }
    Mint &operator--()
    {
        --mval;
        return *this;
    }
    Mint operator--(int)
    {
        Mint ret{*this};
        // --*this;
        operator--();
        return ret;
    }

    // aritmetik operatorler
    // hemen hepsi simetrik. global operator function tanımlanmalı. Mümkünse friend kullanmayın.
    friend Mint operator+(const Mint &lhs, const Mint &rhs)
    {
        return Mint{lhs} += rhs;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs)
    {
        return Mint{lhs} -= rhs;
    }
    friend Mint operator*(const Mint &lhs, const Mint &rhs)
    {
        return Mint{lhs} *= rhs;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs)
    {
        return Mint{lhs} /= rhs;
    }
    friend Mint operator%(const Mint &lhs, const Mint &rhs)
    {
        return Mint{lhs} %= rhs;
    }

    // Inserter / extractor
    friend std::ostream &operator<<(std::ostream &os, const Mint &x)
    {
        return os << '(' << x.mval << ')';
    }

    // extractor fonksiyonları iostream kütüphanesini öğrendikten sonra tekrar ele alacağız
    friend std::istream &operator>>(std::istream &is, Mint &x)
    {
        return is >> x.mval;
    }

    // Equality

    friend bool operator==(const Mint &lhs, const Mint &rhs)
    {
        return lhs.mval == rhs.mval;
    }

    friend bool operator!=(const Mint &lhs, const Mint &rhs)
    {
        return !(lhs == rhs);
    }

    // Comparasion

    friend bool operator<(const Mint &lhs, const Mint &rhs)
    {
        return lhs.mval < rhs.mval;
    }

    friend bool operator>(const Mint &lhs, const Mint &rhs)
    {
        return lhs > rhs;
    }

    friend bool operator>=(const Mint &lhs, const Mint &rhs)
    {
        return !(lhs < rhs);
    }

    friend bool operator<=(const Mint &lhs, const Mint &rhs)
    {
        return !(lhs > rhs);
    }

    Mint &operator+=(const Mint &other)
    {
        mval += other.mval;
        return *this;
    }
    Mint &operator-=(const Mint &other)
    {
        mval -= other.mval;
        return *this;
    }
    Mint &operator*=(const Mint &other)
    {
        mval *= other.mval;
        return *this;
    }
    Mint &operator/=(const Mint &other)
    {
        mval /= other.mval;
        return *this;
    }
    Mint &operator%=(const Mint &other)
    {
        mval %= other.mval;
        return *this;
    }

    static Mint random_mint()
    {
        return Mint{std::rand()};
    }

private:
    int mval;
};

// std::ostream& operator<<(std::ostream&, const Mint&); // friend olmazsa global olması için namespace'te yazmamız gerekiyor.

#endif // MINT_H
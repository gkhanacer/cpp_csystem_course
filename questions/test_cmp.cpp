#include <iostream>
#include <cstring>

union MCMode
{
    struct 
    {
        /* data */
        std::uint8_t chargingMode   : 1;
        std::uint8_t cleaningMode   : 2;
        std::uint8_t mopMode        : 1;
        std::uint8_t specialMode    : 2;
        std::uint8_t mapMode        : 1;
        std::uint8_t statusMode     : 3;
        std::uint8_t batteryMode    : 1;
    };
    std::uint16_t mbyte;

};


int main(int argc, char const *argv[])
{
    MCMode m1, m2;
    // memset(&m1, 0, sizeof(MCMode));
    // memset(&m2, 0, sizeof(MCMode));
    m2.mbyte = 6;
    m1.mbyte = 6;
    m1.

    if(memcmp(&m1, &m2, sizeof(MCMode)) == 0) 
        std::cout << "yes";
    else    
        std::cout << "no";

    return 0;
}

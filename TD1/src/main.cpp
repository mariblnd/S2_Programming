#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 2, 10 };
    float d1 {static_cast<float>(f1)};
    Fraction f2 { 1, 2 };

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    std::cout << f1 + f2 << std::endl;
    std::cout << f1 - f2 << std::endl;
    std::cout << f1 * f2 << std::endl;
    std::cout << f1 / f2 << std::endl;

    std::cout << (f1 == f2) << std::endl;
    std::cout << (f1 != f2) << std::endl;

    std::cout << d1 << std::endl;






    return 0;
}
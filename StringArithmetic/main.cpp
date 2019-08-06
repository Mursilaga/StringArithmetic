#include <iostream>
#include "StringCalc.h"


int main() {
    std::string a, b, result;

    while (1) {
        std::cout << "input a\n";
        std::cin >> a;
        std::cout << "input b\n";
        std::cin >> b;
        std::cout << a << " + " << b << " = " << StringCalc::add(a, b) << "\n\n";
    }

    return 0;
}

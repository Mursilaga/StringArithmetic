#include <iostream>
#include "StringCalc.h"


int main() {
    std::string a, b, result;
    std::cout << "String Arithmetic\n";
    std::cout << "subtract integers, positive and/or negative. (no floats)\n";
    while (1) {
        std::cout << "input a\n";
        std::cin >> a;
        std::cout << "input b\n";
        std::cin >> b;
        std::cout << a << " - " << b << " = " << StringCalc::subtract(a, b) << "\n\n";
    }

    return 0;
}

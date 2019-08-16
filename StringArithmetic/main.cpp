#include <iostream>
#include "StringCalc.h"
#include <time.h> 

int main() {
    std::string a, b, result = "0";
    a = "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    b = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    clock_t start, end;
    double seconds;
    std::cout << "String Arithmetic\n";
    while (1) {
        //std::cout << "input a\n";
        //std::cin >> a;
        //std::cout << "input b\n";
        //std::cin >> b;
        start = clock();
        for (auto i = 0; i < 100000; ++i)
            result = StringCalc::add(result, b);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << a << " * " << b << " = " << result << "\ntime: " << seconds <<" sec \n\n";
        std::cin >> a;
    }

    return 0;
}

#include <iostream>
#include "StringCalc.h"
#include <time.h> 

int main() {
    std::string a, b, result = "0";
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
        for (auto i = 0; i < 10000; ++i)
            result = StringCalc::add_fast(result, b);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << a << " * " << b << " = " << result << "\ntime: " << seconds <<" sec \n\n";
    }

    return 0;
}

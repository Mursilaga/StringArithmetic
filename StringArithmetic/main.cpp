#include <iostream>
#include "StringCalc.h"
#include <time.h> 

int main() {
    std::string a, b, result = "0";
    clock_t start, end;
    double seconds;

    std::cout << "String Arithmetic\n";

    while (1) {
        std::cout << "input a\n";
        std::cin >> a;
        std::cout << "input b\n";
        std::cin >> b;
        start = clock();
        result = StringCalc::multiply(a, b);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << a << " * " << b << " = " << result << "\ntime: " << seconds <<" sec \n\n";
    }

    return 0;
}

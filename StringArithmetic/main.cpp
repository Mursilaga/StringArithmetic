#include <iostream>
#include "StringCalc.h"


int main()
{
    std::string a, b, result;

    while (1) 
    {
        std::cout << "input a\n";
        std::cin >> a;
        std::cout << "input b\n";
        std::cin >> b;
        StringCalc::less(a, b) ? result = "<" : result = ">";
        std::cout << a  << " " << result << " " << b << "\n\n";
    }

    return 0;
}

#include <iostream>
#include "StringCalc.h"
#include <time.h> 

int main() {
    std::string a, b, result;
    clock_t start, end;
    double seconds;

    std::cout << "String Arithmetic\n";  

    while (1) {
        std::cout << "input a\n";
        std::cin >> a;
        //a = "190206641047684975211982941460081069318934411454082336992200675048562064076120070994322604415891801";
        start = clock();
        result = StringCalc::sqrt(a);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << "root(" << a << ")" << " = " << result << "\ntime: " << seconds << " sec \n\n";
    }

    return 0;
}

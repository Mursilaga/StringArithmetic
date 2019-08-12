#pragma once
#include <string>
class StringCalcInteger {
public:

    static void deleteLeadingZeros(std::string& str) {
        int start_pos = 0;
        for (auto digit : str) {
            if (digit == '0')
                start_pos++;
            else
                break;
        }
        str = str.substr(start_pos);
        if (str == "")
            str = "0";
    }


    //return true if a > b, otherwise return false
    static bool more(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);

        if (a.length() != b.length())
            return a.length() > b.length();

        for (auto a_symbol = a.begin(), b_symbol = b.begin();
             a_symbol < a.end() && b_symbol < b.end();
             ++a_symbol, ++b_symbol) {
            if (*a_symbol != *b_symbol)
                return *a_symbol > *b_symbol;
        }
        return false;
    }

    //return true if a >= b, otherwise return false
    static bool more_or_eq(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        return more(a, b) || a == b;
    }

    //return true if a < b, otherwise return false
    static bool less(std::string a, std::string b) {
        return more(b, a);
    }

    //return true if a <= b, otherwise return false
    static bool less_or_eq(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        return less(a, b) || a == b;
    }

    //return a + b
    static std::string add(std::string a, std::string b) {
        std::string res = "";

        bool over = false;
        for (auto it_a = a.rbegin(), it_b = b.rbegin();
             ;
             ++it_a, ++it_b) {

            if (it_a >= a.rend()) {
                res.insert(0, b.substr(0, std::distance(it_b, b.rend())));
                break;
            }

            if (it_b >= b.rend()) {
                res.insert(0, a.substr(0, std::distance(it_a, a.rend())));
                break;
            }

            int r = (*it_a - '0') + (*it_b - '0');

            if (over) {
                r++;
                over = false;
            }

            if (r >= 10) {
                over = true;
                r %= 10;
            }
            res.insert(0, std::to_string(r));
        }
        if (over)
            res.insert(0, "1");

        deleteLeadingZeros(res);
        return res;
    }

    //return a - b
    static std::string subtract(std::string a, std::string b) {
        if (a == b)
            return "0";

        if (isNegative(a) && isNegative(b))
            return subtract(b.substr(1), a.substr(1));
        else if (isNegative(a))
            return add(b, a.substr(1)).insert(0, "-");
        else if (isNegative(b))
            return add(a, b.substr(1));

        if (less(a, b))
            return subtract(b, a).insert(0, "-");
        
        std::string res = "";
        bool over = false;
        for (auto it_a = a.rbegin(), it_b = b.rbegin();
             ;
             ++it_a, ++it_b) {
            
            int r = 0;
            if (it_a < a.rend())
                r = (*it_a - '0');
            else
                break;

            if (over) {
                r--;
                over = false;
            }

            if (it_b >= b.rend()) {
                res.insert(0, std::to_string(r));
                res.insert(0, a.substr(0, std::distance(++it_a, a.rend())));
                break;
            }

            r -= (*it_b - '0');

            if (r < 0) {
                over = true;
                r += 10;
            }

            res.insert(0, std::to_string(r));
        }
        deleteLeadingZeros(res);
        return res;
    }

    //return true if a is negative number, otherwise return false
    static bool isNegative(std::string a) {
        return *a.begin() - '0' < 0;
    }

    static std::string divide(std::string a, int b) {
        std::string res = "";
        bool over = false;
        int digit = 0;

        for (char symbol : a) {
            digit = symbol - '0';
            if (over) {
                digit += 10;
                over = false;
            }
            if (digit < b) {
                res += "0";
                if (digit == 1)
                    over = true;
            }
            else {
                res += std::to_string(digit / b);
                if (digit % b)
                    over = true;
            }
        }

        if (res == "")
            res = "0";
        else if (res.length() > 1 && res[0] == '0')
            res = res.substr(1);

        return res;
    }
};

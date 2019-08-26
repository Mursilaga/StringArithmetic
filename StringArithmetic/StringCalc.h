#pragma once
#include "StringCalcInteger.h"

class StringCalc : public StringCalcInteger {
public:
    static std::string add(std::string a, std::string b) {
        std::string res = "";
        char decimal_separator = ',';

        size_t a_comma_pos = a.find(",");
        size_t b_comma_pos = b.find(",");
        if (a_comma_pos == std::string::npos) {
            a_comma_pos = a.find(".");
            decimal_separator = '.';
        }
        if (b_comma_pos == std::string::npos) {
            b_comma_pos = b.find(".");
            decimal_separator = '.';
        }
        size_t result_comma_pos_reverse = 0;

        if (a_comma_pos != std::string::npos
            && b_comma_pos == std::string::npos) {
            res = a.substr(a_comma_pos);
            a = a.substr(0, a_comma_pos);
        }
        else if (b_comma_pos != std::string::npos
                 && a_comma_pos == std::string::npos) {
            res = b.substr(b_comma_pos);
            b = b.substr(0, b_comma_pos);
        }
        else if (a_comma_pos != std::string::npos
                 && b_comma_pos != std::string::npos) {
            std::string a_fract = a.substr(a_comma_pos + 1);
            std::string b_fract = b.substr(b_comma_pos + 1);
            int diff = a_fract.length() - b_fract.length();
            if (diff < 0)
                a_fract.insert(a_fract.length(), -diff, '0');
            else if (diff > 0)
                b_fract.insert(b_fract.length(), diff, '0');

            result_comma_pos_reverse = a_fract.length();

            a = a.substr(0, a_comma_pos) + a_fract;
            b = b.substr(0, b_comma_pos) + b_fract;
        }

        return processDecimal(&__super::add, a, b, result_comma_pos_reverse, decimal_separator);
    }

    static std::string multiply(std::string a, std::string b) {
        std::string res = "";
        char decimal_separator = ',';

        size_t a_comma_pos = a.find(",");
        size_t b_comma_pos = b.find(",");
        if (a_comma_pos == std::string::npos) {
            a_comma_pos = a.find(".");
            if (a_comma_pos == std::string::npos)
                a_comma_pos = a.length();
            decimal_separator = '.';
        }
        if (b_comma_pos == std::string::npos) {
            b_comma_pos = b.find(".");
            if (b_comma_pos == std::string::npos)
                b_comma_pos = b.length();
            decimal_separator = '.';
        }
        a.erase(a_comma_pos, 1);
        b.erase(b_comma_pos, 1);
        size_t result_comma_pos_reverse = (a.length() - a_comma_pos) + (b.length() - b_comma_pos);

        res = processDecimal(&__super::multiply, a, b, result_comma_pos_reverse, decimal_separator);

        if(result_comma_pos_reverse > 0)
            deleteTrailingZeros(res, decimal_separator);

        return res;
    }


private:

    static std::string processDecimal(std::string(*func)(std::string, std::string),
                                       std::string a, std::string b,
                                       size_t separator_pos_reverse, char decimal_separator) {
        std::string res = "";
        res.insert(0, func(a, b));
        
        if (res == "0")
            return res;
        if (separator_pos_reverse >= res.length())
            res.insert(0, (separator_pos_reverse + 1) - res.length(), '0');
        if (separator_pos_reverse > 0)
            res.insert(res.length() - separator_pos_reverse, 1, decimal_separator);

        return res;
    }

    static void deleteTrailingZeros(std::string& str, char separator = '.') {
        unsigned pos = str.length() - 1;
        while (pos >= 0 && (str[pos] == '0' || str[pos] == separator))
            pos--;

        str = str.erase(pos+1);
        if (str == "")
            str = "0";
    }
};


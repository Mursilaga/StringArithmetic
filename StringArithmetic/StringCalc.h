#pragma once
#include "StringCalcInteger.h"

class StringCalc : public StringCalcInteger
{
public:
    static std::string add(std::string a, std::string b)
    {
        std::string res = "";
        //size_t a_comma_pos = a.find(",");
        //size_t b_comma_pos = b.find(",");
        //size_t result_comma_pos_reverse = 0;
        //
        //if (a_comma_pos != std::string::npos
        //    && b_comma_pos == std::string::npos)
        //{
        //    res = a.substr(a_comma_pos);
        //    a = a.substr(0, a_comma_pos);
        //}
        //else if (b_comma_pos != std::string::npos
        //    && a_comma_pos == std::string::npos)
        //{
        //    res = b.substr(b_comma_pos);
        //    b = b.substr(0, b_comma_pos);
        //}
        //else if (a_comma_pos != std::string::npos
        //    && b_comma_pos != std::string::npos)
        //{
        //    std::string a_fract = a.substr(a_comma_pos + 1);
        //    std::string b_fract = b.substr(b_comma_pos + 1);
        //    int diff = a_fract.length() - b_fract.length();
        //    if (diff < 0)
        //        a_fract.insert(a_fract.length(), -diff, '0');
        //    else if (diff > 0)
        //        b_fract.insert(b_fract.length(), diff, '0');
        //
        //    result_comma_pos_reverse = a_fract.length();
        //
        //    a = a.substr(0, a_comma_pos) + a_fract;
        //    b = b.substr(0, b_comma_pos) + b_fract;
        //
        //}

        //int diff = a.length() - b.length();
        //if (diff < 0)
        //    a.insert(0, -diff, '0');
        //else if (diff > 0)
        //    b.insert(0, diff, '0');

        res = __super::add(a, b);

        //res.insert(res.length() - result_comma_pos_reverse, 1, ',');

        return res;
    }
};


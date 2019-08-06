#pragma once
#include <string>
class StringCalcInteger
{
public:

    static void deleteLeadingZeros(std::string& str)
    {
        int start_pos = 0;
        for (auto digit : str)
        {
            if (digit == '0')
                start_pos++;
            else
                break;
        }
        str = str.substr(start_pos);
    }


    //return true if a > b, otherwise retun false
    static bool more(std::string a, std::string b)
    {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);

        if (a.length() != b.length())
            return a.length() > b.length();

        for (auto a_symbol = a.begin(), b_symbol = b.begin();
            a_symbol < a.end() && b_symbol < b.end();
            ++a_symbol, ++b_symbol)
        {
            if (*a_symbol != *b_symbol)
                return *a_symbol > *b_symbol;
        }
        return false;
    }

    //return true if a >= b, otherwise retun false
    static bool more_or_eq(std::string a, std::string b)
    {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        return more(a, b) || a == b;
    }

    //return true if a < b, otherwise retun false
    static bool less(std::string a, std::string b)
    {
        return more(b, a);
    }

    //return true if a <= b, otherwise retun false
    static bool less_or_eq(std::string a, std::string b)
    {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        return less(a, b) || a == b;
    }

    static std::string add(std::string a, std::string b)
    {
        std::string res;

        size_t a_comma_pos = a.find(",");
        size_t b_comma_pos = b.find(",");
        size_t result_comma_pos_reverse = 0;

        if (a_comma_pos != std::string::npos
            && b_comma_pos == std::string::npos)
        {
            res = a.substr(a_comma_pos);
            a = a.substr(0, a_comma_pos);
        }
        else if (b_comma_pos != std::string::npos
            && a_comma_pos == std::string::npos)
        {
            res = b.substr(b_comma_pos);
            b = b.substr(0, b_comma_pos);
        }
        else if (a_comma_pos != std::string::npos
            && b_comma_pos != std::string::npos)
        {
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

        int diff = a.length() - b.length();
        if (diff < 0)
            a.insert(0, -diff, '0');
        else if (diff > 0)
            b.insert(0, diff, '0');

        bool over = false;
        for (auto it_a = a.rbegin(), it_b = b.rbegin();
            it_a < a.rend() && it_b < b.rend();
            ++it_a, ++it_b)
        {
            int r = (*it_a - '0') + (*it_b - '0');

            if (over)
            {
                r++;
                over = false;
            }

            if (r >= 10)
            {
                over = true;
                r %= 10;
            }
            res.insert(0, std::to_string(r));
        }
        if (over)
            res.insert(0, "1");

        res.insert(res.length() - result_comma_pos_reverse, 1, ',');
        return res;
    }

    static std::string divide(std::string a, int b)
    {
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

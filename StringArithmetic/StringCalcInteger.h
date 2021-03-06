#pragma once
#include <string>
#include <vector>

class StringCalcInteger {
public:

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
    static bool moreOrEq(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        return more(a, b) || a == b;
    }

    //return true if a < b, otherwise return false
    static bool less(std::string a, std::string b) {
        return more(b, a);
    }

    //return true if a <= b, otherwise return false
    static bool lessOrEq(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        return less(a, b) || a == b;
    }

    //return a + b
    static std::string addSimple(std::string a, std::string b) {
        int diff = a.length() - b.length();
        if (diff < 0)
            a.insert(0, -diff, '0');
        else if (diff > 0)
            b.insert(0, diff, '0');
        
        std::string res = "";
        bool over = false;
        int r = 0;
        for (auto it_a = a.rbegin(), it_b = b.rbegin();
             it_a < a.rend();
             ++it_a, ++it_b) {

            r = (*it_a - '0') + (*it_b - '0');

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

    //return a + b
    static std::string addChunkByChunk(std::string a, std::string b) {
        int diff = a.length() - b.length();
        if (diff < 0)
            a.insert(0, -diff, '0');
        else if (diff > 0)
            b.insert(0, diff, '0');

        unsigned chunk_size = 9;
        std::string res = "";
        bool over = false;
        int r = 0;

        std::string tmp_a = "", tmp_b = "";
        for (unsigned i = a.length(); i > 0; ) {
            
            if (i > chunk_size) {
                tmp_a = a.substr(i - chunk_size, chunk_size);
                tmp_b = b.substr(i - chunk_size, chunk_size);
                i -= chunk_size;
            }
            else {
                tmp_a = a.substr(0, i);
                tmp_b = b.substr(0, i);
                i = 0;
            }

            r = (atoi(tmp_a.c_str()) + atoi(tmp_b.c_str()));

            if (over) {
                r++;
                over = false;
            }

            if (r >= 1000000000) {
                over = true;
                r %= 1000000000;
            }
            res.insert(0, std::to_string(r).insert(0, chunk_size - std::to_string(r).length(), '0'));
        }
        if (over)
            res.insert(0, "1");

        deleteLeadingZeros(res);
        return res;
    }

    //return a + b
    static std::string add(std::string a, std::string b) {
        int diff = a.length() - b.length();
        if (diff < 0)
            a.insert(0, -diff, '0');
        else if (diff > 0)
            b.insert(0, diff, '0');

        unsigned chunk_size = 18;
        std::string res = "";
        bool over = false;
        uint64_t r = 0;

        std::string tmp_a = "", tmp_b = "";
        for (unsigned i = a.length(); i > 0; ) {

            if (i > chunk_size) {
                tmp_a = a.substr(i - chunk_size, chunk_size);
                tmp_b = b.substr(i - chunk_size, chunk_size);
                i -= chunk_size;
            }
            else {
                tmp_a = a.substr(0, i);
                tmp_b = b.substr(0, i);
                i = 0;
            }

            r = (stoll(tmp_a) + stoll(tmp_b));

            if (over) {
                r++;
                over = false;
            }

            if (r >= 1000000000000000000) {
                over = true;
                r %= 1000000000000000000;
            }
            res.insert(0, std::to_string(r).insert(0, chunk_size - std::to_string(r).length(), '0'));
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
        
        int diff = a.length() - b.length();
        if (diff < 0)
            a.insert(0, -diff, '0');
        else if (diff > 0)
            b.insert(0, diff, '0');

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

    //return a * b
    static std::string multiplySimple(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        if (a == "0" || b == "0")
            return "0";

        std::string res = "0";
        for (auto it_b = b.rbegin(); it_b < b.rend(); ++it_b)
            for (auto it_a = a.rbegin(); it_a < a.rend(); ++it_a)
                res = addSimple(res, std::to_string((*it_a - '0') * (*it_b - '0')).append(std::distance(a.rbegin(), it_a), '0').append(std::distance(b.rbegin(), it_b), '0'));
        return res;
    }

    //return a * b
    static std::string multiply(std::string a, std::string b) {
        deleteLeadingZeros(a);
        deleteLeadingZeros(b);
        if (a == "0" || b == "0")
            return "0";

        unsigned chunk_size = 9;
        std::string res = "0", tmp_a, tmp_b, tmp_res;

        for (auto it_a = a.length(); it_a > 0;) {
            if (it_a > chunk_size)
                tmp_a = a.substr(it_a - chunk_size, chunk_size);
            else
                tmp_a = a.substr(0, it_a);

            for (auto it_b = b.length(); it_b > 0;) {
                if (it_b > chunk_size)
                    tmp_b = b.substr(it_b - chunk_size, chunk_size);
                else
                    tmp_b = b.substr(0, it_b);

                tmp_res = std::to_string((stoll(tmp_a) * stoll(tmp_b)));
                res = add(res, tmp_res.append((a.length() - it_a) + (b.length() - it_b), '0'));

                if (it_b > chunk_size)
                    it_b -= chunk_size;
                else
                    it_b = 0;
            }
            if (it_a > chunk_size) 
                it_a -= chunk_size;
            else
                it_a = 0;
        }
        return res;
    }

    //return (int) a / b quotient and reminder
    static std::vector<std::string> divide_with_rem(std::string a, std::string b) {
        std::string quotient = "", tmp_a = "";
        uint8_t tmp_res;
        if (b == "0")
            return std::vector<std::string> {"err", "err"};

        for (auto it_a = a.begin(); it_a < a.end(); it_a++) {
            tmp_a += *it_a;
            if (less(tmp_a, b)) {
                quotient.append("0");
                continue;
            }
            tmp_res = 1;
            while (moreOrEq(tmp_a, multiply(b, std::to_string(tmp_res + 1))))
                tmp_res++;
            quotient.append(std::to_string(tmp_res));
            tmp_a = subtract(tmp_a, multiply(b, std::to_string(tmp_res)));
        }

        deleteLeadingZeros(quotient);
        deleteLeadingZeros(tmp_a);
        return std::vector<std::string> {quotient, tmp_a};
    }

    //return (int) a / b
    static std::string divide(std::string a, std::string b) {
        std::string quotient = "", tmp_a = "";
        uint8_t tmp_res;
        if (b == "0")
            return "err";

        for (auto it_a = a.begin(); it_a < a.end(); it_a++) {
            tmp_a += *it_a;
            if (less(tmp_a, b)) {
                quotient.append("0");
                continue;
            }
            tmp_res = 1;
            while (moreOrEq(tmp_a, multiply(b,std::to_string(tmp_res+1))))
                tmp_res++;
            quotient.append(std::to_string(tmp_res));
            tmp_a = subtract(tmp_a, multiply(b,std::to_string(tmp_res)));
        }

        deleteLeadingZeros(quotient);
        deleteLeadingZeros(tmp_a);
        return quotient;
    }

    static std::string sqrt(std::string a) {
        std::string x = a.substr(0, a.length()/2 + 1), y;
        if (a == "0") return "0";
        while (true) {
            y = divide(add(x,divide(a, x)),"2");
            if (moreOrEq(y,x))
                return x;
            else
                x = y;
        }
    }

private:

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

};

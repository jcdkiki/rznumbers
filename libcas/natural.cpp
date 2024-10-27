#include "natural.hpp"
#include <algorithm>
#include <iostream>
#include <cctype>

Natural::Natural() : digits(1, 0) {}

Natural::Natural(std::vector<Digit> digits): digits(digits) {}

std::ostream& operator<<(std::ostream& os, const Natural& number)
{
    for (ssize_t i = number.digits.size() - 1; i >= 0; --i) {
        os << (char)(number.digits[i] + '0');
    }
    return os;
}

std::istream& operator>>(std::istream& is, Natural& number)
{
    char c;
    number.digits.resize(0);

    while (true) {
        c = is.get();
        if (is.fail() || !std::isspace(c))
            break;
    }

    while (true) {
        if (is.fail() || !std::isdigit(c))
            break;
        
        number.digits.push_back(c - '0');
        c = is.get();
    }

    is.unget();

    if (number.digits.size() == 0) {
        number.digits.push_back(0);
    }

    std::reverse(number.digits.begin(), number.digits.end());

    return is;
}

int Natural::cmp(const Natural &n1, const Natural &n2) {
    if (n1.digits.size() > n2.digits.size()) {
        return 2; // n1 > n2
    }

    else if (n1.digits.size() < n2.digits.size()) {
        return 1; // n1 < n2
    }

    else {
        for (size_t i = n1.digits.size(); i > 0; --i) {
            if (n1.digits[i] > n2.digits[i]) {
                return 2; // n1 > n2
            } 
            else if (n1.digits[i] < n2.digits[i]) {
                return 1; // n1 < n2
            }
        }
    }
    return 0; // n1 == n2
}

bool Natural::operator==(const Natural &rhs) const
{
    return (Natural::cmp(*this, rhs) == 0);
}

bool Natural::operator!=(const Natural &rhs) const
{
    return (Natural::cmp(*this, rhs) != 0);
}

bool Natural::operator>(const Natural &rhs) const
{
    return (Natural::cmp(*this, rhs) == 2);
}

bool Natural::operator<(const Natural &rhs) const
{
    return (Natural::cmp(*this, rhs) == 1);
}

bool Natural::operator>=(const Natural &rhs) const
{
    int res = Natural::cmp(*this, rhs);
    return (res == 2) || (res == 0);
}

bool Natural::operator<=(const Natural &rhs) const
{
    int res = Natural::cmp(*this, rhs);
    return (res == 1) || (res == 0);
}

Natural mul(Natural n1, Natural n2) {
    Natural::Digit carry = 0;
    Natural res;
    res.digits.resize(n1.digits.size() + n2.digits.size());

    for (size_t i = 0; i < n1.digits.size(); ++i) {
        for (size_t j = 0; j < n2.digits.size() || carry; ++j) {
            size_t temp = res.digits[i + j] + n1.digits[i] * (j < n2.digits.size() ? n2.digits[j]: 0) + carry;
            res.digits[i + j] = temp % Natural::BASE;
            carry = temp / Natural::BASE;
        }
    }

    //strip insignificant zeros 000123 => 123
    while (res.digits.size() > 1 && res.digits.back() == 0) {
        res.digits.pop_back();
    }
    return res;
}

Natural Natural::operator*(const Natural &number) const {
    return mul(Natural(this->digits), number);
}
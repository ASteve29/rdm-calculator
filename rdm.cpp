#include "rdm.h"

#include <string>
#include <vector>
#include <iostream>

// --- DigitSequence ---

int DigitSequence::get_digit(size_t index) const {
    return digits[index] - '0';
}

size_t DigitSequence::size() const {
    return digits.size();
}

void DigitSequence::left_shift() {
    digits.push_back('0');
}

void DigitSequence::right_shift() {
    if(!digits.empty()) {
        digits.pop_back();
    }
}

std::ostream& operator<<(std::ostream& os, const DigitSequence& sequence) {
    for(char c: sequence.digits) {
        os << c;
    }
    return os;
}


// --- RDMInteger ---

RDMInteger RDMInteger::operator+(const RDMInteger &n) {
    const std::vector<char>* longer_string = nullptr;
    const std::vector<char>* shorter_string = nullptr;
    RDMInteger result;

    if(digits.size()>=n.size()) {
        longer_string = &digits;
        shorter_string = &n.digits;
    } else {
        longer_string = &n.digits;
        shorter_string = &digits;
    }

    size_t len_dif = longer_string->size() - shorter_string->size();
    int calc;
    int digit;
    int carry = 0;

    for(int i = longer_string->size()-1; i > -1; i--) {
        if(i >= len_dif) {
            calc = ((*longer_string)[i] - '0') + ((*shorter_string)[i-len_dif] - '0') + carry;
        } else {
            calc = ((*longer_string)[i] - '0') + carry;
        }

        digit = calc%10;
        carry = calc/10;
        result.digits.insert(result.digits.begin(), digit + '0');
    }

    if(carry!=0) {
        result.digits.insert(result.digits.begin(), carry + '0');
    }

    return result;
}

RDMInteger& RDMInteger::operator+=(const RDMInteger &n) {
    *this = *this + n;
    return *this;
}

RDMInteger RDMInteger::multiply_by_digit(const RDMInteger& n, int digit) {
    RDMInteger result("0");

    for(int i = 0; i < digit; i++) {
        result += n;
    }
    return result;
}

RDMInteger RDMInteger::operator*(const RDMInteger &n) {
    RDMInteger result("0");

    int shift = 0;
    for(char digit : n.digits) {
        RDMInteger partial =  multiply_by_digit(*this, digit - '0');

        for(int i = 0; i < shift; i++) {
            partial.left_shift();
        }

        result += partial;
        shift++;
    }
    return result;
}


// --- RDMDecimal ---




// --- RDMNumber ---

RDMNumber::RDMNumber(const std::string& digits) {
    size_t decimalPoint = digits.find('.');

    if (decimalPoint == std::string::npos) {
        intValue = RDMInteger(digits);
        decimalValue = RDMDecimal("0");
    }
    else {
        intValue = RDMInteger(digits.substr(0, decimalPoint));
        decimalValue = RDMDecimal(digits.substr(decimalPoint + 1));
    }
}

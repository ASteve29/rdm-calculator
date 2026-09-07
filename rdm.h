#pragma once

#include <vector>
#include <string>
#include <iostream>

class DigitSequence {
    protected:
        std::vector<char> digits;
    
    public:
        DigitSequence() = default;
        DigitSequence(const std::string& str) : digits(str.begin(), str.end()) {}

        int get_digit(size_t index) const;
        size_t size() const;
        
        void left_shift();
        void right_shift();
        friend std::ostream& operator<<(std::ostream& os, const DigitSequence& sequence);
};

class RDMInteger : public DigitSequence {
    public:
        using DigitSequence::DigitSequence;

        RDMInteger operator+(const RDMInteger &n);
        RDMInteger& operator+=(const RDMInteger &n);
        RDMInteger operator*(const RDMInteger &n);
        RDMInteger multiply_by_digit(const RDMInteger& n, int digit);
};

class RDMDecimal : public DigitSequence {
    public:
        using DigitSequence::DigitSequence;
};

class RDMNumber {
    private:
        RDMInteger intValue;
        RDMDecimal decimalValue;
    public:
        RDMNumber() = default;
        RDMNumber(const std::string& digits);


};
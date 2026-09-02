#pragma once

#include <vector>
#include <string>
#include <iostream>

class DigitSequence {
    protected:
        std::string digits;
    
    public:
        DigitSequence() = default;
        DigitSequence(const std::string& digits) : digits(digits) {}

        int get_digit(size_t index) const;
        size_t size() const;
        
        friend std::ostream& operator<<(std::ostream& os, const DigitSequence& sequence);
};

class RDMInteger : public DigitSequence {
    public:
        using DigitSequence::DigitSequence;
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
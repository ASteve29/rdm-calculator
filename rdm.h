#pragma once

#include <vector>
#include <string>
#include <iostream>

class DigitSequence {
    protected:
        std::string digits;
    
    public:
        DigitSequence() = default;
        
};

class RDMInteger : public DigitSequence {

};

class RDMDecimal : public DigitSequence {

};

class RDMNumber {
    private:
        RDMInteger intValue;
        RDMDecimal decimalValue;

    public:
};
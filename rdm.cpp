#include "rdm.h"

// DigitSequence

int DigitSequence::get_digit(size_t index) const {
    return digits[index] - '0';
}

size_t DigitSequence::size() const {
    return digits.size();
}

std::ostream& operator<<(std::ostream& os, const DigitSequence& sequence) {
    os << sequence.digits;
    return os;
}



// RDMNumber

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

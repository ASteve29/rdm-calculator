#include "rdm.h"
#include <iostream>


int main() {
    DigitSequence num = DigitSequence("1234567890");

    std::cout << "Test 1: Intitialising a DigitSequence number to 1234567890 and returning it. " 
    << num << std::endl;

    num.right_shift();
    std::cout << "Test 2: Right shift (Expected 123456789) " 
    << num << std::endl;

    num.left_shift();
    std::cout << "Test 3: Left shift (Expected 1234567890) " 
    << num << std::endl;

    std::cout << "Test 4: Get 3rd digit (Expected 3) " 
    << num.get_digit(2) << std::endl;

    std::cout << "Test 5: Returning size (Expected 10) " 
    << num.size() << std::endl;

    RDMInteger num1("12345");
    RDMInteger num2("67890");
    RDMInteger result = num1 + num2;

    std::cout << "Test 6: Add 2 RDMIntegers of same length: 12345 and 67890 "
    << result << std::endl;

    num1 = RDMInteger("123456");
    num2 = RDMInteger("7890");
    result = num1 + num2;

    std::cout << "Test 6: Add 2 RDMIntegers of different length: 123456 and 7890 "
    << result << std::endl;

    num1 = RDMInteger("999");
    num2 = RDMInteger("1");
    result = num1 + num2;

    std::cout << "Test 7: Testing carry with 999 and 1 "
    << result << std::endl;

    return 0;
}
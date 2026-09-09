#include "rdm.h"
#include <iostream>


int main() {

    // --- Basic Commands ---

    DigitSequence num = DigitSequence("1234567890");

    std::cout << "Test 1: Intitialising a DigitSequence number to 1234567890 and returning it:\n" 
    << num << std::endl;

    num.right_shift();
    std::cout << "Test 2: Right shift \n(Expected 123456789): " 
    << num << std::endl;

    num.left_shift();
    std::cout << "Test 3: Left shift \n(Expected 1234567890): " 
    << num << std::endl;

    std::cout << "Test 4: Get 3rd digit \n(Expected 3): " 
    << num.get_digit(2) << std::endl;

    std::cout << "Test 5: Returning size \n(Expected 10): " 
    << num.size() << std::endl;

    // --- Addition ---

    RDMInteger num1("123");
    RDMInteger num2("456");
    RDMInteger result = num1 + num2;

    std::cout << "Test 6: Add 2 RDMIntegers of same length: 123 and 456 \n(Expected 579): "
    << result << std::endl;

    num1 = RDMInteger("120");
    num2 = RDMInteger("14");
    result = num1 + num2;

    std::cout << "Test 7: Add 2 RDMIntegers of different length: 120 and 14 \n(Expected 134): "
    << result << std::endl;

    num1 = RDMInteger("999");
    num2 = RDMInteger("1");
    result = num1 + num2;

    std::cout << "Test 8: Testing carry with 999 and 1 \n(Expected 1000): "
    << result << std::endl;

    // --- Multiplication ---

    num1 = RDMInteger("1234");
    num2 = RDMInteger("567");
    result = num1 * num2;

    std::cout << "Test 9: Multiplying 2 numbers, 1234 and 567 \n(Expected 699678): "
    << result << std::endl;

    num1 = RDMInteger("20");
    num2 = RDMInteger("0");
    result = num1 * num2;

    std::cout << "Test 10: Multiplying by 0, 20 and 0 \n(Expected 0): "
    << result << std::endl;

    result = num2 * num1;

    std::cout << "Test 11: Multiplying 0 by a number, 0 and 10 \n(Expected 0): "
    << result << std::endl;

    /*
    This test shows how RDMIntegers can 
    have extra zeros and would be treated 
    the same, maybe add a "simplify" function 
    call to the end of each operation?
    */

    num1 = RDMInteger("999");
    num2 = RDMInteger("999");
    result = num1 * num2;

    std::cout << "Test 11: Multiplying carry heavy, 999 and 999 \n(Expected 998001): "
    << result << std::endl;

    return 0;
}
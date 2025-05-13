#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class BigInteger {
private:
    int* digits; 
    size_t size; // разряды
    static const int base = 10; // сс

public:
    // кбп
    BigInteger();

    // ксп
    BigInteger(const char* number);

    
    ~BigInteger();

    
    BigInteger(const BigInteger& other); // кк
    BigInteger& operator=(const BigInteger& other); // ок
    BigInteger(BigInteger&& other) noexcept; // кп
    BigInteger& operator=(BigInteger&& other) noexcept; // оп

    // i/o
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& bigInt);
    friend std::istream& operator>>(std::istream& is, BigInteger& bigInt);

    // шоб удобно по ращрядам чекать
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

   
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator*(int multiplier) const;
    
    BigInteger operator*(const BigInteger& other) const;
    
    BigInteger power(int exponent) const;


    // Другие методы
    void normalize(); // убрать нули в начале числа
};

#endif // BIGINTEGER_H

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class BigInteger {
private:
    int* digits; 
    size_t size; // �������
    static const int base = 10; // ��

public:
    // ���
    BigInteger();

    // ���
    BigInteger(const char* number);

    
    ~BigInteger();

    
    BigInteger(const BigInteger& other); // ��
    BigInteger& operator=(const BigInteger& other); // ��
    BigInteger(BigInteger&& other) noexcept; // ��
    BigInteger& operator=(BigInteger&& other) noexcept; // ��

    // i/o
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& bigInt);
    friend std::istream& operator>>(std::istream& is, BigInteger& bigInt);

    // ��� ������ �� �������� ������
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

   
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator*(int multiplier) const;
    
    BigInteger operator*(const BigInteger& other) const;
    
    BigInteger power(int exponent) const;


    // ������ ������
    void normalize(); // ������ ���� � ������ �����
};

#endif // BIGINTEGER_H

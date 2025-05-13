#pragma once

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include <cmath>

class ComplexNumber {
private:
    double modulus; // r
    double angle;   // phi

public:
    
    ComplexNumber(); 
    ComplexNumber(double m, double a);

    
    ~ComplexNumber();

    //������� ����
    ComplexNumber(const ComplexNumber& other);                // ����������� �����������
    ComplexNumber& operator=(const ComplexNumber& other);     // �������� ������������
    ComplexNumber(ComplexNumber&& other) noexcept;            // ����������� �����������
    ComplexNumber& operator=(ComplexNumber&& other) noexcept; // �������� �����������

    //���������� ��������

    ComplexNumber operator+(const ComplexNumber& other) const; 
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const; 
    ComplexNumber operator^(int power) const;
    ComplexNumber Csqrt() const; 

    // ���������� �������� �����/������
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& cn);
};

#endif // COMPLEXNUMBER_H

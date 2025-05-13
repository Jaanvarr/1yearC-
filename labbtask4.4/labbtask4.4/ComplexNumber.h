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

    //правило пяти
    ComplexNumber(const ComplexNumber& other);                // Конструктор копирования
    ComplexNumber& operator=(const ComplexNumber& other);     // Оператор присваивания
    ComplexNumber(ComplexNumber&& other) noexcept;            // Конструктор перемещения
    ComplexNumber& operator=(ComplexNumber&& other) noexcept; // Оператор перемещения

    //перегрузка операций

    ComplexNumber operator+(const ComplexNumber& other) const; 
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const; 
    ComplexNumber operator^(int power) const;
    ComplexNumber Csqrt() const; 

    // Перегрузка операций ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& cn);
};

#endif // COMPLEXNUMBER_H

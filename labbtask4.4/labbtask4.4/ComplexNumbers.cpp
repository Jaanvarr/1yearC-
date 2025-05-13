#include "ComplexNumber.h"
#include "math.h"

ComplexNumber::ComplexNumber() : modulus(0), angle(0) {}


ComplexNumber::ComplexNumber(double m, double a) : modulus(m), angle(a) {}

ComplexNumber::~ComplexNumber() {}

ComplexNumber::ComplexNumber(const ComplexNumber& other) : modulus(other.modulus), angle(other.angle) {}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
    if (this != &other) {
        modulus = other.modulus;
        angle = other.angle;
    }
    return *this;
}

ComplexNumber::ComplexNumber(ComplexNumber&& other) noexcept : modulus(other.modulus), angle(other.angle) {
    other.modulus = 0;
    other.angle = 0;
}

ComplexNumber& ComplexNumber::operator=(ComplexNumber&& other) noexcept {
    if (this != &other) {
        modulus = other.modulus;
        angle = other.angle;
        other.modulus = 0;
        other.angle = 0;
    }
    return *this;
}

ComplexNumber ComplexNumber::Csqrt() const {
    return ComplexNumber(std::sqrt(modulus), angle / 2);
}


ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    double real1 = modulus * cos(angle);
    double imag1 = modulus * sin(angle);
    double real2 = other.modulus * cos(other.angle);
    double imag2 = other.modulus * sin(other.angle);

    double realResult = real1 + real2;
    double imagResult = imag1 + imag2;

    double resultModulus = std::sqrt((realResult * realResult) + (imagResult * imagResult));
    double resultAngle = atan2(imagResult, realResult);

    return ComplexNumber(resultModulus, resultAngle);
}


ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    double real1 = modulus * cos(angle);
    double imag1 = modulus * sin(angle);
    double real2 = other.modulus * cos(other.angle);
    double imag2 = other.modulus * sin(other.angle);

    double realResult = real1 - real2;
    double imagResult = imag1 - imag2;

    double resultModulus = std::sqrt(realResult * realResult + imagResult * imagResult);
    double resultAngle = atan2(imagResult, realResult);

    return ComplexNumber(resultModulus, resultAngle);
}


ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    return ComplexNumber(modulus * other.modulus, angle + other.angle);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    return ComplexNumber(modulus / other.modulus, angle - other.angle);
}

ComplexNumber ComplexNumber::operator^(int power) const {
    return ComplexNumber(pow(modulus, power), angle * power);
}



std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
    double real = cn.modulus * cos(cn.angle);
    double imag = cn.modulus * sin(cn.angle);
    os << real << " + " << imag << "i"; //a + bi
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumber& cn) {
    double m, a;
    std::cout << "Enter modulus and angle (in radians): ";
    is >> m >> a;
    cn = ComplexNumber(m, a); 
    return is;
}

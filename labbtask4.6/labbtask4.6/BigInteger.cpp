#include "BigInteger.h"


BigInteger::BigInteger() : size(1) {
    digits = new int[size];
    digits[0] = 0;
}


BigInteger::BigInteger(const char* number) {
    size = strlen(number);
    digits = new int[size];
    for (size_t i = 0; i < size; ++i) {
        if (isdigit(number[i])) {
            digits[i] = number[i] - '0';
        }
        else {
            throw std::invalid_argument("Invalid character in number");
        }
    }
    normalize();
}


BigInteger::~BigInteger() {
    delete[] digits;
}

BigInteger::BigInteger(const BigInteger& other) : size(other.size) {
    digits = new int[size];
    std::memcpy(digits, other.digits, size * sizeof(int));
}


BigInteger& BigInteger::operator=(const BigInteger& other) {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        digits = new int[size];
        std::memcpy(digits, other.digits, size * sizeof(int));
    }
    return *this;
}


BigInteger::BigInteger(BigInteger&& other) noexcept : digits(other.digits), size(other.size) {
    other.digits = nullptr;
    other.size = 0;
}


BigInteger& BigInteger::operator=(BigInteger&& other) noexcept {
    if (this != &other) {
        delete[] digits;
        digits = other.digits;
        size = other.size;
        other.digits = nullptr;
        other.size = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& bigInt) {
    for (size_t i = 0; i < bigInt.size; ++i) {
        os << bigInt.digits[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, BigInteger& bigInt) {
    std::string number;
    is >> number;
    bigInt = BigInteger(number.c_str());
    return is;
}


int& BigInteger::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return digits[index];
}

const int& BigInteger::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return digits[index];
}


BigInteger BigInteger::operator+(const BigInteger& other) const {
    size_t maxSize = std::max(size, other.size);
    BigInteger result;
    delete[] result.digits; // освобождаем память, если она была выделена!!!
    result.size = maxSize + 1; //макс размер + 1 если carry
    result.digits = new int[result.size]();

    int carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        int sum = carry;
        if (i < size) sum += digits[size - 1 - i]; //+ разрядов первого числа
        if (i < other.size) sum += other.digits[other.size - 1 - i]; //+ разрядов второго числа
        result.digits[result.size - 1 - i] = sum % base; // текущий разряд
        carry = sum / base; 
    }
    if (carry) {
        result.digits[0] = carry; // carry->старший разряд
    }
    else {
        result.size--; // !carry
        memmove(result.digits, result.digits + 1, result.size * sizeof(int)); //сдвииг разрядов
    }
    return result;
}

// * на <10
BigInteger BigInteger::operator*(int multiplier) const {
    if (multiplier < 0) {
        throw std::invalid_argument("Multiplier must be non-negative");
    }

    BigInteger result;
    delete[] result.digits;
    result.size = size + 1; 
    result.digits = new int[result.size]();

    int carry = 0;
    for (size_t i = 0; i < size; ++i) {
        int product = digits[size - 1 - i] * multiplier + carry;
        result.digits[result.size - 1 - i] = product % base; 
        carry = product / base; 
    }
    if (carry) {
        result.digits[0] = carry; 
    }
    else {
        result.size--; 
        memmove(result.digits, result.digits + 1, result.size * sizeof(int)); 
    }
    return result;
}


BigInteger BigInteger::operator*(const BigInteger& other) const {
    BigInteger result; 
    result.size = size + other.size; 
    result.digits = new int[result.size](); 

    
    for (size_t i = 0; i < size; ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.size; ++j) {
            int product = digits[size - 1 - i] * other.digits[other.size - 1 - j] + result.digits[result.size - 1 - (i + j)] + carry;
            result.digits[result.size - 1 - (i + j)] = product % base; 
            carry = product / base; 
        }
        if (carry) {
            result.digits[result.size - 1 - (i + other.size)] += carry; 
        }
    }

    result.normalize(); 
    return result;
}


BigInteger BigInteger::power(int exponent) const {
    if (exponent < 0) {
        throw std::invalid_argument("Exponent must be non negative");
    }
    BigInteger result("1"); 
    BigInteger base = *this; 

    while (exponent > 0) {
        if (exponent % 2 == 1) { 
            result = result * base; 
        }
        base = base * base; 
        exponent /= 2;
    }
    return result;
}


void BigInteger::normalize() {
    size_t leadingZeros = 0;
    while (leadingZeros < size && digits[leadingZeros] == 0) {
        leadingZeros++;
    }
    if (leadingZeros == size) {
    
        digits[0] = 0;
        size = 1;
    }
    else {
        
        size -= leadingZeros;
        memmove(digits, digits + leadingZeros, size * sizeof(int));
    }
}


#include <iostream>
#include <string>
#include <cmath>
double hexToDecimal(const std::string& hex);
std::string removeCharsWithFrequencyTwo(const std::string& input) {
    std::string result;
    std::string temp = input; 

    
    for (size_t i = 0; i < temp.size(); ++i) {
        char ch = temp[i];
        int count = 0;

       
        for (size_t j = 0; j < temp.size(); ++j) {
            if (temp[j] == ch) {
                count++;
            }
        }

      
        if (count != 2) {
            result += ch;
        }

        
    }

    return result;
}

int main() {
    std::string text;
    std::cout << "enter text: ";
    std::getline(std::cin, text);

    std::string modifiedText = removeCharsWithFrequencyTwo(text);
    std::cout << "result text:\n";
    std::cout << modifiedText << std::endl;

    std::string hexNumber, hexNumber2;
    std::cout << "enter HEX: ";
    std::cin >> hexNumber;

    try {
        double decimalNumber = hexToDecimal(hexNumber);
        std::cout << "HEX to DEC: " << decimalNumber << std::endl;
        hexNumber2 = std::to_string(decimalNumber);
        std::cout << hexNumber2 << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}



double hexToDecimal(const std::string& hex) {
    double decimalValue = 0.0;
    size_t pointPosition = hex.find('.');

    
    if (pointPosition != std::string::npos) {
        for (size_t i = 0; i < pointPosition; ++i) {
            char ch = hex[i];
            int value;

            if (ch >= '0' && ch <= '9') {
                value = ch - '0';
            }
            else if (ch >= 'A' && ch <= 'F') {
                value = ch - 'A' + 10;
            }
            else if (ch >= 'a' && ch <= 'f') {
                value = ch - 'a' + 10;
            }
            else {
                throw std::invalid_argument("Invalid hexadecimal character");
            }

            decimalValue = decimalValue * 16 + value;
        }
    }

    // Обработка дробной части
    if (pointPosition != std::string::npos) {
        for (size_t i = pointPosition + 1; i < hex.size(); ++i) {
            char ch = hex[i];
            int value;

            if (ch >= '0' && ch <= '9') {
                value = ch - '0';
            }
            else if (ch >= 'A' && ch <= 'F') {
                value = ch - 'A' + 10;
            }
            else if (ch >= 'a' && ch <= 'f') {
                value = ch - 'a' + 10;
            }
            else {
                throw std::invalid_argument("Invalid hexadecimal character");
            }

            decimalValue += value / pow(16, i - pointPosition);
        }
    }

    return decimalValue;
}


   


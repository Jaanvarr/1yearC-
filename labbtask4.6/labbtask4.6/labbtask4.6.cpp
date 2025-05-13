#include <iostream>
#include "BigInteger.h"

int main() {
    try {
        BigInteger base("8212890625");
        int exponent = 5;

        BigInteger result = base.power(exponent); 
        std::cout << base << " ^ " << exponent << " = " << result << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error!: " << e.what() << std::endl;
    }

    return 0;
}

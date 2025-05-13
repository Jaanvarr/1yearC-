#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>

int MinValue = 94;
int MaxValue = 727;


bool CheckWeight(int x) {
    if ((x < MinValue) || (x > MaxValue)) {
        
        return true;
    }
    else {
        return false;
    }
        
}

int MaxOfTwo(int Num1, int Num2) {
    return (Num1 >= Num2) ? Num1 : Num2;
}

int main() {

    int M1, M2, M3, MaxWeight;
    std::cin >> M1 >> M2 >> M3;

    if (CheckWeight(M1)) {
        std::cout << "Error" << std::endl;      //Error check level 1
        return 0;                               
    }
    else if (CheckWeight(M2)) {
        std::cout << "Error" << std::endl;      //Error check level 2
        return 0;
    }
    else if (CheckWeight(M3)) {
        std::cout << "Error" << std::endl;      //Error check level 3
        return 0;
    }

    std::cout << MaxOfTwo(M1, MaxOfTwo(M2, M3)) << std::endl;

    _getch();
    return 0;
}
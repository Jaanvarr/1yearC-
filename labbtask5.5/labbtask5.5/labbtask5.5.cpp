#include <iostream>
#include <fstream>
#include <string>
#include <stack>

int main()
{
    std::string inputFilePath = "input.cpp";
    std::string outputFilePath = "loops_info.txt"; 

    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }


}


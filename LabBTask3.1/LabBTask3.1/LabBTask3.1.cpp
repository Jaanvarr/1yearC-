#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_SIZE = 1000; 
const int MAX_FILENAME_LENGTH = 256; 

int readNums(const char* filename, int numbers[]) {
    std::ifstream inputFile(filename);
    int count = 0;
    int number;

    if (!inputFile) {
        std::cout << "Error opening file. " << filename << std::endl;
        return 0;
    }

    while (inputFile >> number && count < MAX_SIZE) {
        numbers[count++] = number;
    }

    inputFile.close();
    return count; // число чисел
}

void writeNums(const char* inputFilename, const char* outputFilename) {
    //int numbers[MAX_SIZE];
    //int count = readNums(inputFilename, numbers);
    //int filteredNumbers[MAX_SIZE];
    //int filteredCount = 0;

    //int indexPlus = 1;
    //int indexMinus = 1;
    int number;
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cout << "Error opening file " << outputFilename << std::endl;
        return;
    }
    //for (int i = 0; i < count; ++i) {
    //    // проверка по таске
    //    if (filteredCount == 0 || (filteredNumbers[filteredCount - 1] < 0 && numbers[i] < 0) || (filteredNumbers[filteredCount - 1] > 0 && numbers[i] > 0)) {
    //        continue;
    //    }
    //    filteredNumbers[filteredCount++] = numbers[i];
    //}

    //int i = 0;
    //int j = 0;
    int posPlus = 0;
    int posMinus = 0;
    while (!inputFile.eof())
    {
        inputFile.seekg(posPlus);
      
        while(true)
        {
            inputFile >> number;
            
            if (number >= 0)
                break;
           
        }
        outputFile << number << std::endl;
        //inputFile >> number;
        posPlus = inputFile.tellg();
        
        inputFile.seekg(posMinus);
       // inputFile >> number;
        while (true)
        {
            inputFile >> number;
            if (number < 0)
                break;
        }
        outputFile << number << std::endl;
        //inputFile >> number;
        posMinus = inputFile.tellg();
        
        
       

    }

    /*for (int i = 0; i < filteredCount; ++i) {
        outputFile << filteredNumbers[i] << std::endl;
    }*/

    outputFile.close();
}

int main() {
    char inputFile[MAX_FILENAME_LENGTH] = "31B_file_input.txt";  
    char outputFile[MAX_FILENAME_LENGTH] = "31B_file_output.txt";  

    writeNums(inputFile, outputFile);

    return 0;
}

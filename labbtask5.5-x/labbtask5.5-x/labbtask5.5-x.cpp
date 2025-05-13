#include <iostream>
#include <fstream>
#include <string>
#include <stack>

void removeComments(std::string& line) {
    // Удаляем однострочные комментарии
    size_t singleLineComment = line.find("//");
    if (singleLineComment != std::string::npos) {
        line.erase(singleLineComment);
    }

    // Удаляем многострочные комментарии
    size_t multiLineStart = line.find("/*");
    size_t multiLineEnd = line.find("*/");
    while (multiLineStart != std::string::npos && multiLineEnd != std::string::npos) {
        line.erase(multiLineStart, multiLineEnd - multiLineStart + 2);
        multiLineStart = line.find("/*");
        multiLineEnd = line.find("*/");
    }
}

bool isLoopStart(const std::string& line) {
    return line.find("for") != std::string::npos || line.find("while") != std::string::npos || line.find("do") != std::string::npos;
}

int main() {
    std::string inputFilePath = "input.cpp";
    std::string outputFilePath = "loops_info.txt";

    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::stack<std::pair<std::string, int>> loopStack;
    int lineNumber = 0;
    int braceCount = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        removeComments(line);

        // Проверяем наличие циклов
        if (isLoopStart(line)) {
            loopStack.push(std::make_pair(line, lineNumber));
        }

        // Подсчитываем количество открывающих и закрывающих скобок
        for (char ch : line) {
            if (ch == '{') {
                braceCount++;
            }
            else if (ch == '}') {
                if (!loopStack.empty()) {
                    // Уменьшаем количество скобок только если есть открывающая
                    if (braceCount > 0) {
                        braceCount--;
                        auto loopInfo = loopStack.top();
                        loopStack.pop();
                        std::cout << loopInfo.first << " loop: Start line " << loopInfo.second << ", End line " << lineNumber << std::endl;
                    }
                }
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

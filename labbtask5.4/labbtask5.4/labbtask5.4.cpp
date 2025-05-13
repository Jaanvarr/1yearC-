#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

void removeComments(std::string& line) {
   
    size_t singleLineComment = line.find("//");
    if (singleLineComment != std::string::npos) {
        line.erase(singleLineComment);
    }

   
    size_t multiLineStart = line.find("/*"); //6
    size_t multiLineEnd = line.find("*/");
    if (multiLineStart != std::string::npos && multiLineEnd != std::string::npos && multiLineEnd > multiLineStart) {
        line.erase(multiLineStart, multiLineEnd - multiLineStart + 2);
    }
}

void removeMultiComm(std::string& line) {
    size_t start = 0;
    while ((start = line.find("/*", start)) != std::string::npos) {
        size_t end = line.find("*/", start);
        if (end == std::string::npos) {
            
            break;
        }
       
        line.erase(start, end - start + 2);
    }
}

bool isLoopStart(const std::string& line) {
    return line.find("for") == 0 || line.find("while") == 0 || line.find("do") == 0;
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
    std::stack<std::pair<int, int>> braceStack;
    std::vector<bool> Priority;
      
    int lineNumber = 0;
    int BraceCount = 0;
    int susCount = 0;
    bool priority = 0;
    while (std::getline(inputFile, line)) {
        lineNumber++;

        
       
        
        if (line.find("/*") != -1)
        {
            while (line.find("*/") == std::string::npos)
            {
                line.erase();
                std::getline(inputFile, line);
                

                if (line.find("/*") != -1)
                    break;
            }

        }


        if (line.find("for") != -1 && line.find('{') != std::string::npos) {
            int temp = lineNumber;
            loopStack.push(std::make_pair("for", temp));
            ++BraceCount;
            Priority.push_back(1);
            
           
        }
        else if (line.find("while") != -1 && line.find('{') != std::string::npos) {
            loopStack.push(std::make_pair("while", lineNumber));
            ++BraceCount;
            Priority.push_back(1);
    
        }
        else if (line.find("do") != -1 && line.find('{') != std::string::npos) {
            loopStack.push(std::make_pair("do", lineNumber));
            ++BraceCount;
            Priority.push_back(1);
            
        }
        else if (line.find('{') != std::string::npos) {
            ++susCount;
            Priority.push_back(0);
        }
            
        
        /*if (line.find('{') != std::string::npos && ((line.find("for") == std::string::npos) || (line.find("do") == std::string::npos) || (line.find("while") == std::string::npos))) {
            ++susCount;
            priority = 0;
        }*/
        
        if (line.find('}') != std::string::npos && Priority.back() == 1)
        {
            --BraceCount;
            Priority.pop_back();
            if (BraceCount == loopStack.size()-1) {
                while (!loopStack.empty()) {
                    std::cout << loopStack.top().first << " loop: Start line " << loopStack.top().second << ", End line " << lineNumber << std::endl;

                    std::pair<std::string, int> loopInfo = loopStack.top();


                    std::pair<std::string, int> info = loopStack.top();

                    loopStack.pop();
                    //std::cout << loopStack.size(); 
                    break;
                }
            }
        }
        else if (line.find('}') != std::string::npos && Priority.back() == 0) {
            Priority.pop_back();
            --susCount;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

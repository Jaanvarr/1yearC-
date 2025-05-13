#include <iostream>
#include <string>
#include <sstream>

bool isVowel(char ch) {
    ch = tolower(ch);//к нижнему регистру
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y');
}



int countVowels(const std::string& word) {
    int count = 0;
    for (char ch : word) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}


std::string findMaxVowels(const std::string& input) {
    std::istringstream stream(input);
    std::string word;
    std::string maxVowelWords; 
    int maxVowelCount = 0;



    
    while (stream >> word) {
        int vowelCount = countVowels(word);


        if (vowelCount > maxVowelCount) {
            maxVowelCount = vowelCount;
            maxVowelWords = word; 
        }
        else if (vowelCount == maxVowelCount) {
            maxVowelWords += " " + word; 
        }
    }

    return maxVowelWords; 
}

int main() {
    std::string text;
    std::cout << "enter text: ";
    std::getline(std::cin, text);

    std::string MaxVowels = findMaxVowels(text);
    std::cout << "max vowels: " << MaxVowels << std::endl;

    return 0;
}

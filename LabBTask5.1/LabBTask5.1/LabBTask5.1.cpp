#include <iostream>
#include <string>

std::string removeCharsWithFrequencyTwo(const std::string& input) {
    std::string result;
    std::string temp = input; // Временная строка для подсчета символов

    // Подсчет частоты символов
    for (size_t i = 0; i < temp.size(); ++i) {
        char ch = temp[i];
        int count = 0;

        // Подсчет количества вхождений символа
        for (size_t j = 0; j < temp.size(); ++j) {
            if (temp[j] == ch) {
                count++;
            }
        }

        // Если символ встречается не два раза, добавляем его в результат
        if (count != 2) {
            result += ch;
        }

        // Удаляем все вхождения символа из временной строки, чтобы не считать их повторно
        for (size_t j = 0; j < temp.size(); ++j) {
            if (temp[j] == ch) {
                temp[j] = '\0'; // Заменяем символ на нулевой символ
            }
        }
    }

    return result;
}

int main() {
    std::string text;
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    std::string modifiedText = removeCharsWithFrequencyTwo(text);
    std::cout << "Текст после удаления символов, встречающихся ровно два раза:\n";
    std::cout << modifiedText << std::endl;

    return 0;
}

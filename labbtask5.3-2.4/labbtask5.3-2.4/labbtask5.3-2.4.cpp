#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void CheckForIdentical(std::list<char>& List) {
    List.sort(); //Сортируем список
    List.unique(); 
}

void FillList(std::list<char>& l) {
    for (int i = 0; i < 10; i++) {
        l.push_back(static_cast<char>(rand() % 7 + 128)); //Генерация символов
    }
}

void CreateList(const std::list<char>& l1, const std::list<char>& l2, std::list<char>& ResList) {
    auto p1 = l1.begin();
    auto p2 = l2.begin(); // по-хорошему писать std::list<char>::iterator p2 = l2.begin();
    while (p1 != l1.end() && p2 != l2.end()) {
        ResList.push_back(*p1);
        ResList.push_back(*p2);
        ++p1;
        ++p2;
    }
}

void ViewList(const std::list<char>& l) {
    for (const char& c : l) {
        std::cout << c << ' '; //Добавляем пробел между символами
    }
    std::cout << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //Инициализация генератора случайных чисел

    std::list<char> list1;
    std::list<char> list2;
    std::list<char> ResList;

    FillList(list1);
    ViewList(list1);
    FillList(list2);
    ViewList(list2);
    CreateList(list1, list2, ResList);
    ViewList(ResList);
    CheckForIdentical(ResList);
    ViewList(ResList);

    return 0;
}

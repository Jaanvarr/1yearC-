#include <iostream>
#include <list>

void ViewList(const std::list<int>& l) {
    for (const int& c : l) {
        std::cout << c << ' '; // Добавляем пробел между символами
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;

    std::list<int> list;

    for (int i = 0; i < 2 * n; i++)
    {
        list.push_back(i);
    }

    ViewList(list);
    std::cout << std::endl;

    int Product = 1;

    auto tempStart = list.begin();
    auto tempEnd = --list.end(); 
    auto constStart = tempStart;

    while (next(constStart) != tempEnd)
    {
        Product *= (*tempStart - *tempEnd);
        ++tempStart;   
        ++tempStart;
        --tempEnd;
        --tempEnd;
    }

    std::cout << Product;

    return 0;
}


#include "Header.h"

void Enter(std::vector<BASEofALL*>&, unsigned int n);
void VectorOutput(const std::vector<BASEofALL*>&);
bool inputFromFile(std::vector<BASEofALL*>&, std::istream& in);
void EraseArray(std::vector<BASEofALL*>&);
void outputToFile(const std::vector<BASEofALL*>&, std::ofstream& out);
void EraseElement(std::vector<BASEofALL*>&, int i);


int main()
{
    std::vector<BASEofALL*> oh_my_god;
    int n;
    std::cout << "Skoka?"
        << std::endl;
    std::cin >> n;

    Enter(oh_my_god, n);
    VectorOutput(oh_my_god);
    std::cout << "-----------------" << std::endl;

    std::ofstream O_file("output.txt");

    outputToFile(oh_my_god, O_file);
    O_file.close();

    EraseArray(oh_my_god);

    std::vector<BASEofALL*> br;

    std::ifstream I_file("input.txt");
    bool p = inputFromFile(br, I_file);

    I_file.close();

    if (!p)
        return 9;

    VectorOutput(br);
    EraseArray(br);

    return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

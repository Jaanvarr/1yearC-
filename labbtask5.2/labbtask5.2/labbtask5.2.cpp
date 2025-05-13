#include <vector>
#include <iostream>

double MinimumOutOfN(std::vector<std::vector<int>> C, int index_line, int index_column, int MatrixSize)
{
    double min = C[index_line][index_column];
    while (index_column < MatrixSize && index_line < MatrixSize)
    {
        if (C[index_line][index_column] < min)
            min = C[index_line][index_column];
        index_column++;
        index_line++;
    }
    return min;
}

// функция вывода матрицы на экран 
void vyvod(std::vector<std::vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)// Цикл по строкам 
    {                   // Цикл по элементам в строке 
        for (int j = 0; j < vec[i].size(); j++)
            std::cout << vec[i][j] << ' ';
        // Вывод элементов i строки вектора 
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int a = 5;
    std::vector<int> rows(a, 0);
    std::vector<std::vector<int>> Matrix;

    for (int i = 0; i < a; i++)
    {
        std::vector<int> temp;

        for (int j = 0; j < a; j++)
        {
            temp.push_back(rand() % 10);
        }
        Matrix.push_back(temp);
    }
    
    vyvod(Matrix);

    std::vector<int>ResVector(2 * a - 1, 0);

    int VectorIndex = 0;
    int index_line = a - 1;
    int index_column = 0;
    for (VectorIndex; VectorIndex < a - 1; VectorIndex++)
    {
        ResVector[VectorIndex] = MinimumOutOfN(Matrix, index_line, index_column, a);

        index_line--;

    }
    for (VectorIndex; VectorIndex < 2 * a - 1; VectorIndex++)
    {
        ResVector[VectorIndex] = MinimumOutOfN(Matrix, index_line, index_column, a);


        index_column++;
    }
    for (unsigned int i = 0; i < ResVector.size(); i++)
        std::cout << ResVector[i] << " ";
    std::cout << std::endl;

    
    return 0;
}




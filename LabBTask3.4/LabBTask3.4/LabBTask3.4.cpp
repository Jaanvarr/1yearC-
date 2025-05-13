#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_STUDENTS = 100; // Максимальное количество студентов
const int NAME_LENGTH = 100;   // Максимальная длина ФИО
const int PERFORMANCE_LENGTH = 20; // Максимальная длина успеваемости

struct Student {
    char fullName[NAME_LENGTH];
    int age;
    char gender; // 'M' или 'F'
    int course;
    char performance[PERFORMANCE_LENGTH];
};

// Функция для создания файла с данными студентов
void createStudentFile(const char* filename) {
    Student students[MAX_STUDENTS] = {
        {"Ivanov Ivan Ivanovich", 20, 'M', 1, "Good"},
        {"Petrova Anna Sergeevna", 21, 'F', 2, "Excellent"},
        {"Sidorov Alexei Viktorovich", 22, 'M', 1, "Good"},
        {"Kuznetsova Maria Paulavna", 20, 'F', 3, "Good"}
    };

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error reading file." << std::endl;
        return;
    }

    file << std::setw(15) << "Name" << std::setw(15) << "Age" << std::setw(15) << "Gender" << std::setw(15) << "Year" << std::setw(15) << "Performance" << std::endl; // Заголовки
    for (int i = 0; i < 4; ++i) {
        file << std::setw(15) << students[i].fullName << std::setw(15)
            << students[i].age << std::setw(15)
            << students[i].gender << std::setw(15)
            << students[i].course << std::setw(15)
            << students[i].performance << "\n";
    }

    file.close();
}

// Функция для просмотра файла
void viewStudentFile(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error reading file." << std::endl;
        return;
    }

    char line[256];
    while (file.getline(line, sizeof(line))) {
        std::cout << line << std::endl;
    }

    file.close();
}

// Функция для фильтрации студентов по курсу и создания нового файла
void filterStudentsByCourse(const char* inputFilename, const char* outputFilename, int courseNumber) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile || !outputFile) {
        std::cerr << "Error reading file.." << std::endl;
        return;
    }
    /*if (!outputFile) {
        std::cerr << "Error reading file." << std::endl;
        return;
    }*/

    char line[256];
    outputFile << std::setw(5) << "Name" << std::setw(5) << "Age" << std::setw(5) << "Gender" << std::setw(5) << "Year" << std::setw(5) << "Performance" << std::endl;// Заголовки
    inputFile.getline(line, sizeof(line)); // Пропустить заголовок

    while (inputFile.getline(line, sizeof(line))) {
        int course;
        sscanf_s(line, "%[^,],%*d,%*c,%d,%*s", line, &course); // Извлечение курса
        if (course == courseNumber) {
            outputFile << line << "\n"; // Запись в выходной файл
        }
    }

    inputFile.close();
    outputFile.close();
}

// Основная часть программы
int main() {
    const char* filename = "students.txt";
    createStudentFile(filename);
    std::cout << "File contents:\n";
    viewStudentFile(filename);

    int courseToFilter = 1;
    char outputFilename[50];
    sprintf_s(outputFilename, "students_course.txt", courseToFilter);
    filterStudentsByCourse(filename, outputFilename, courseToFilter);
    std::cout << "\nFile " << courseToFilter << " created: " << outputFilename << std::endl;
    viewStudentFile("students_course.txt");
    return 0;
}

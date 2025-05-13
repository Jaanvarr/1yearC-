#include <iostream>
#include <fstream>

const int MAX_STUDENTS = 100; // Максимальное количество студентов
const int MAX_NAME_LENGTH = 100; // Максимальная длина ФИО
const int MAX_PERFORMANCE_LENGTH = 20; // Максимальная длина успеваемости

struct Student {
    char fullName[MAX_NAME_LENGTH];
    int age;
    char gender; // M для мужчин F для женщин
    int year;
    double GPA;

    
    void writeToFile(std::ofstream& out) const {
        out.write(fullName, MAX_NAME_LENGTH);
        out.write(reinterpret_cast<const char*>(&age), sizeof(age));
        out.write(&gender, sizeof(gender));
        out.write(reinterpret_cast<const char*>(&year), sizeof(year));
        out.write(reinterpret_cast<const char*>(&GPA), sizeof(GPA));
    }

    
    void readFromFile(std::ifstream& in) {
        in.read(fullName, MAX_NAME_LENGTH);
        in.read(reinterpret_cast<char*>(&age), sizeof(age));
        in.read(&gender, sizeof(gender));
        in.read(reinterpret_cast<char*>(&year), sizeof(year));
        in.read(reinterpret_cast<char*>(&GPA), sizeof(GPA));
    }
};

void createFile(const char* filename, Student students[], int count) {
    std::ofstream out(filename, std::ios::binary);
    for (int i = 0; i < count; ++i) {
        students[i].writeToFile(out);
    }
}

void viewFile(const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    while (in.peek() != EOF) {
        Student student;
        student.readFromFile(in);
        std::cout << "Name: " << student.fullName << ", Age: " << student.age
            << ", Gender: " << student.gender << ", Year: " << student.year
            << ", GPA: " << student.GPA << std::endl;
    }
}

void filterStudentsByCourse(const char* filename1, const char* filename2, int courseNumber) {
    std::ifstream in(filename1, std::ios::binary);
    std::ofstream out(filename2, std::ios::binary);
    //filteredCount = 0;
    while (in.peek() != EOF) {
        Student student;
        student.readFromFile(in);
        if (student.year == courseNumber) {
            student.writeToFile(out);
            //filteredStudents[filteredCount++] = student;
        }
    }
}

void saveFilteredStudents(const char* filename, Student filteredStudents[], int count) {
    std::ofstream out(filename, std::ios::binary);
    for (int i = 0; i < count; ++i) {
        filteredStudents[i].writeToFile(out);
    }
}

int main() {
    //создание массива студентов
    Student students[MAX_STUDENTS] = {
        {"Ivanov Ivan Ivanovich", 18, 'M', 1, 7.7},
        {"Petrov Peter Petrovich", 20, 'M', 2, 9.8},
        {"Sidorova Ann Sergeevna", 17, 'F', 1, 5.5},
        {"Kuznetsova Mary Vladimirovna", 21, 'F', 3, 8.0},
    };

    int studentCount = 4; 

    //cоздание 
    createFile("students.bin", students, studentCount);

    //посмоp
    std::cout << "File contents:" << std::endl;
    viewFile("students.bin");

    //по курсу
    int courseNumber = 1;
    //Student filteredStudents[MAX_STUDENTS];
    int filteredCount;
    filterStudentsByCourse("students.bin", "filtered_students.bin", courseNumber);

    //cохранение отфильтрованных студентов в новый файл
    //saveFilteredStudents("filtered_students.bin", filteredStudents, filteredCount);

    std::cout << "\nStudents of year " << courseNumber << ":" << std::endl;
    viewFile("filtered_students.bin");

    return 0;
}

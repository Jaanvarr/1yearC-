
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
const int n = 20;

char ManNames[n][n] = { "Ivan", "Brad", "Vlados", "Arnold", "John", "Tim", "Michael", "Vovka", "Valentine", "Vlad" };
char ManSurnames[n][n] = { "Egorov", "Polyakov", "White", "Noob", "Dyatchik", "Ratkevich", "Sobol", "Prokopovich", "Papich", "Dubovik" };

char WomanNames[n][n] = { "Kate", "Mary", "Ann", "Chi", "Tacy", "Jennifer", "Monika", "Lega", "Zina", "Valya" };
char WomanSurnames[n][n] = { "Krug", "Kvadrat", "White", "Kyadkich", "Bird", "Noob", "Weiss", "Prokopovich", "Mamich", "Dubovik" };



struct Student
{
    char* fname = new char[n];
    char* iname = new char[n];
    

    int year;
    int age;
    double GPA;

    char gender;
};


Student createStudent(Student& student)
{
    student.age = rand() % 4 + 17;
    student.year = student.age - 16 + rand() % 2;
    student.GPA = (rand() % 70 + 40) / 10.0;
    if (rand() % 2 == 0)
    {
        student.gender = 'M';
        student.fname = ManSurnames[rand() % 10];
        student.iname = ManNames[rand() % 10];
    }
    else
    {
        student.gender = 'M';
        student.fname = WomanSurnames[rand() % 10];
        student.iname = WomanNames[rand() % 10];
    }
    return student;
}

void createFile(const char* filename, const char* extrafilename, int SeekenYear)
{
    std::ofstream file(filename);
    std::ofstream extraFile(extrafilename);
    if (!file)
    {
        std::cout << "Cannot read initial file.";
        return;
    }

    for (int i = 0; i < 20; i++)
    {
        Student student;
        student = createStudent(student);
        file << std::setw(15) << student.fname << std::setw(15) << student.iname << std::setw(15) << student.age << std::setw(14) << student.gender << std::setw(14) << student.year << std::setw(14) << student.GPA << std::setw(5) << std::endl;
        if (student.year == SeekenYear)
            extraFile << std::setw(15) << student.fname << std::setw(15) << student.iname << std::setw(15) << student.age << std::setw(14) << student.gender << std::setw(14) << student.year << std::setw(14) << student.GPA << std::setw(5) << std::endl;
        //delete student.fname;
        //delete student.iname;
    }
}

void viewFile(const char* filename)
{
    std::fstream infile(filename);
    char v[100];
    infile >> v;
    while (!infile.eof())
    {
        std::cout << v;
        infile >> v;
        std::cout << std::endl;
       
    }
}

int main()
{
    srand(time(NULL));
    const char* filename = "students.txt";
    const char* extrafilename = "extraStudents.txt";
    int SeekenYear = 1;
    createFile(filename, extrafilename, SeekenYear);
    viewFile(filename);
    std::cout << std::endl;
    viewFile(extrafilename);
}
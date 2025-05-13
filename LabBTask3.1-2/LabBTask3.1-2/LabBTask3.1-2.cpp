#include <iostream>
#include <fstream>


void readFile(std::ifstream &infile)
{
    const unsigned MAX = 80;
    char v[MAX];
    infile >> v;
    while (!infile.eof())
    {
        std::cout << v << std::endl;
        infile >> v;
    }
}


void create(std::ofstream& outfile, int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = rand() % 100;
        outfile << v << std::endl;
    }
}

int main()
{
    //std::ofstream outfile("output.txt");
    //int n;
    //std::cin >> n;
    //if (!outfile)
    //{
    //    std::cout << "error1" << std:: endl;
    //    return 1;
    //}

    //create(outfile, n);
    //outfile.close();
    std::ifstream infile("file.txt");

    if (!infile)
    {
        std::cout << "Error: 2" << std::endl;
        return 1;
    }

    readFile(infile);
    infile.close();

    return 0;
}





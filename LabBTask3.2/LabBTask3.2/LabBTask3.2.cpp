#include <iostream>
#include <fstream>
#include <time.h>

void separate(std::fstream& main, size_t size) {
	std::fstream positiveFile("pos.bin", std::ios::binary | std::ios::out /*| std::ios::in*/);
	std::fstream negativeFile("neg.bin", std::ios::binary | std::ios::out /*| std::ios::in*/);
	int temp;
	main.read(reinterpret_cast<char*>(&temp), sizeof(int));
	for (size_t i = 0; i < size; i++)
	{


		if (temp >= 0) {
			positiveFile.write(reinterpret_cast<char*>(&temp), sizeof(int));						//разделяем файлы
		}
		else {
			negativeFile.write(reinterpret_cast<char*>(&temp), sizeof(int));
		}
		main.read(reinterpret_cast<char*>(&temp), sizeof(int));
	}
}

void fill(size_t size) {
	std::fstream positiveFile("pos.bin", std::ios::binary | std::ios::in);
	std::fstream negativeFile("neg.bin", std::ios::binary | std::ios::in);
	std::ofstream resultingFile("res.bin", std::ios::binary);
	int tmp;
	for (size_t i = 0; i < size / 2; i++)
	{

		positiveFile.read(reinterpret_cast<char*>(&tmp), sizeof(int));
		resultingFile.write(reinterpret_cast<char*>(&tmp), sizeof(int));						//по очереди ставим чиселки из разделенных файлов
		negativeFile.read(reinterpret_cast<char*>(&tmp), sizeof(int));
		resultingFile.write(reinterpret_cast<char*>(&tmp), sizeof(int));
	}
}

void showRes(size_t size) {
	std::ifstream res("res.bin", std::ios::binary);
	int tmp;
	for (size_t i = 0; i < size; i++)
	{
		res.read(reinterpret_cast<char*>(&tmp), sizeof(int));		//эт мы снова приводим в инту на вывод
		std::cout << tmp << " ";
	}
}

int main() {
	std::srand(time(NULL));
	size_t size = 50;
	std::fstream start("start.bin", std::ios::binary | std::ios::in | std::ios::out);
	std::fstream res("res.bin", std::ios::binary | std::ios::in | std::ios::out);
	int random_num;
	for (size_t i = 0; i < size; i++)
	{
		random_num = rand() % 100;
		random_num = random_num < 10 ? random_num * 10 + random_num : random_num;			//чиселки снаачала + а потом -
		if (i >= size / 2)		
		{
			random_num *= -1;

		}
		std::cout << random_num << " ";
		start.write(reinterpret_cast<char*>(&random_num), sizeof(int));
	}
	std::cout << std::endl;

	std::cout << std::endl;

	start.close();
	start.open("start.bin", std::ios::in | std::ios::binary);
	separate(start, size);
	fill(size);
	showRes(size);

}
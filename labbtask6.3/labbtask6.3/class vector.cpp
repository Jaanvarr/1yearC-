#include"Header.h"


void EraseArray(std::vector<BASEofALL*>& Array)
{
	for (size_t i = 0; i < Array.size(); i++)
	{
		delete Array[i];
	}
	Array.clear();
}

void Enter(std::vector<BASEofALL*>& Array, unsigned int n)
{
	EraseArray(Array);

	while (Array.size() < n)
	{
		int type = 0;
		std::cout << "Input type of object:\n";
		std::cout << "Ellipse -- 1;\n" <<
			"HyperLinkLabel -- 2;\n" <<
			"TextBox -- 3;\n" <<
			"Button -- 4;\n";

		std::cin >> type;

		switch (type)
		{
		case 1:
		{
			Ellipse* elli = new Ellipse();
			std::cin >> *elli;
			Array.push_back(elli);
			break;
		}
		case 2:
		{
			HyperLinkLabel* hll = new HyperLinkLabel();
			std::cin >> *hll;
			Array.push_back(hll);
			break;
		}
		case 3:
		{
			TextBox* txtb = new TextBox();
			std::cin >> *txtb;
			Array.push_back(txtb);
			break;
		}
		case 4:
		{
			Button* btt = new Button();
			std::cin >> *btt;
			Array.push_back(btt);
			break;
		}
		
		default:
			std::cout << "Error!";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}



void VectorOutput(const std::vector<BASEofALL*>& Array)
{
	for (size_t i = 0; i < Array.size(); i++)
	{
		std::cout << *Array[i];
		std::cout << "-----------------------------------------" << std::endl;
	}

}

void EraseElement(std::vector<BASEofALL*>& Array, int index)
{
	auto p = Array.begin();
	Array.erase(p + index);
}

bool inputFromFile(std::vector<BASEofALL*>& Array, std::istream& in)
{
	EraseArray(Array);
	int n;
	in >> n;
	std::string s; std::getline(in, s);
	for (size_t i = 0; i < n; i++)
	{
		std::string type;
		std::getline(in, type);
		if(type.length() == 0)
			return false;

		BASEofALL* pointer = CreateBase(type.c_str());

		if (!pointer)
			return false;
		if (!pointer->BASE_input_file(in))
		{
			delete pointer;
			return false;
		}
		Array.push_back(pointer);
	}
	return true;
}

void outputToFile(const std::vector<BASEofALL*>& Array, std::ofstream& f)
{
	f << Array.size() << std::endl;

	for (size_t i = 0; i < Array.size(); i++)
	{
		Array[i]->BASE_output_file(f);
	}
}

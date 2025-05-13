#include"Source.cpp"
#include<vector>


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
			Ellipse * elli = new Ellipse();
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
		case 100:
		{
			BASEofALL* boa = new BASEofALL;
			std::cin >> *boa;
			Array.push_back(boa);
		}
		default:
			std::cout << "Error!";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}



void Output(const std::vector<BASEofALL*>& Array)
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




int main()
{
	srand(time(NULL));


	std::vector<BASEofALL*> boomboclat;
	int n;

	Ellipse ellipse1,ellipse2;
	TextBox txtb1, txtb2;
	Button button1, button2;
	HyperLinkLabel hll1, hll2;

	


	

	std::cout << "Skolko?" << std::endl;;
	std::cin >> n;
	Enter(boomboclat, n);
	Output(boomboclat);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	EraseElement(boomboclat, 0);


	Output(boomboclat);
	EraseArray(boomboclat);
	return 0;

}
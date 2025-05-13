#include "vector.h"

int main() {


	srand(time(NULL));


	Vector v(10000000);
	for (int i = 0; i < 1000000; i++)
	{
		v[i] = 0;
	}
	//std::cin >> v;
	for (int i = 0; i < 10000; i++)
	{	
		//long long rnd;
		//std::cin >> rnd;
		int rnd = (rand() % 1000) * (rand() % 1000);
		v[rnd] = rnd;
	}
	for (int i = 0; i < v.Size(); i++)
	{
		if (v[i] > 0) {
			std::cout << v[i] << " ";
		}
	}
	//std::cout << v;
}
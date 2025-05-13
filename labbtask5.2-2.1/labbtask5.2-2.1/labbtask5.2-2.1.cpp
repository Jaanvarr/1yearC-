#include<iostream>
#include<vector>
int main()
{
    const uint64_t MX = 100000001;
    std::vector<int> arr (MX, 0);   //init the array
    for (size_t i = 0; i < MX; i++)
        arr[i] = 0;
    size_t n;
    std::cin >> n;
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
    {
        uint64_t t;
        //cin >> t;

        t = (rand() % 10000) * (rand() % 10000);

        arr[t] = t;                 //assigning the t-value to the t-th array cell
    }
    for (size_t i = 1; i < MX; i++)
        if (arr[i] != 0)
            std::cout << arr[i] << ' ';      //output only the existing elements



                     

    return 0;
}
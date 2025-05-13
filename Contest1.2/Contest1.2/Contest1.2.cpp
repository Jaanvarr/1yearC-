#include <iostream>
#include <math.h>



int main()
{
    int n;
    std::cin >> n;

    if (n > 0) {
        (n % 2) ? n = ((n + 1) >> 1) * n : n = (n >> 1) * (n + 1);     //Overflow protection by bit-shifting
    }
    else if (n == 0) {
        n = 1;
    }
    else {
        n = -n;
        (n % 2) ? n = ((n + 1) >> 1) * n : n = (n >> 1) * (n + 1);
        n = 1 - n;
    }
    std::cout << n;
    return 0;
}
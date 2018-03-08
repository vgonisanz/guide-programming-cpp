#include <iostream>

int main()
{
    int n = 5;

    if(n = 0)   /* Assign!!! Error */
        std::cout << "1: n is zero, n * n = " << n * n << std::endl;
    else
        std::cout << "1: n is not zero, n * n = " << n * n << std::endl;

    if(n == 2)
        std::cout << "2: n is two, n * n = " << n * n << std::endl;
    else
        std::cout << "2: n is not two, n * n = " << n * n << std::endl;

    if(n = 2)   /* Assign!!! Error */
        std::cout << "3: n is two, n * n = " << n * n << std::endl;
    else
        std::cout << "3: n is not two, n * n = " << n * n << std::endl;

    return 0;
}

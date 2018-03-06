#include <iostream>

struct minimal
{
    int onlyone : 1;
}__attribute__ ((packed));

struct several
{
    int first : 3;
    int second : 1;
    long super : 40;
}__attribute__ ((packed));

int main()
{
    minimal small;
    several packed;

    std::cout << "struct minimal:\t\t" << sizeof(small) << " bytes is different than: " << sizeof(int) << " bytes expected." << std::endl;
    std::cout << "struct several:\t\t" << sizeof(packed) << " bytes is different than: " << (2 * sizeof(int) + sizeof(long)) << " bytes expected." << std::endl;

    return 0;
}

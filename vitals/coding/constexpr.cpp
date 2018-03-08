#include <iostream>

int main()
{
    struct Foo { constexpr Foo(int) {} };

    int i = 5;  /* This is fine, 5 is a constant expression */
    Foo x(2);   /* This is fine, 2 is a constant expression and the chosen constructor is constexpr */
    Foo j[] =
    {
        Foo(1),
        Foo(2),
        Foo(3)
    };  /* This if fine too. */

    std::cout << "i value: " << i << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

class Foo
{
    Foo() = default;
    ~Foo() = default;

    Foo(const Foo &copy) = default;

    void doNothing() { /* Nothing */ };
};

int main()
{
    /* Lambda print helper */
    auto print_value = [](int value) { std::cout << "'" << value << "' "; };

    int i;
    i = 7;  /*  Bad practice -- Initialization separate from declaration.
             *  Error if i is used BEFORE have a valid value */

    int j = 10; /* Good one! */

    std::vector<int> v1;    /* Bad practice -- Prefer using brace inicialization */
    v1.push_back(1);
    v1.push_back(2);

    std::vector<int> v2 =
    {   /* Good one!  -- Brace inicialization is awesome */
        1,
        2
    };

    //for
    std::cout << "i was initializated AFTER declaration with value: " << i << std::endl;

    std::cout << "j was initializated in declaration with value: " << j << std::endl;

    std::cout << "v1 has values: ";
    std::for_each(v1.begin(), v1.end(), print_value);
    std::cout << std::endl;

    std::cout << "v2 has values: ";
    std::for_each(v2.begin(), v2.end(), print_value);
    std::cout << std::endl;
    return 0;
}

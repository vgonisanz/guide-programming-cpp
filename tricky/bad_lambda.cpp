#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    /* Lambda print helper */
    auto print_value = [](int value) { std::cout << "'" << value << "' "; };

    std::vector<int> goodVector =
    {
        1,
        2
    };

    /* BAD - The output add one "strange" 1, this is the result of the for_each execution */
    std::cout << "goodVector has values: " << std::for_each(goodVector.begin(), goodVector.end(), print_value) << " <-- ops!" << std::endl;

    /* GOOD ONE */
    std::cout << "goodVector really has values: ";
    std::for_each(goodVector.begin(), goodVector.end(), print_value);
    std::cout << " Aw right!" << std::endl;
    return 0;
}

#include <iostream>

/** Preprocessor to avoid compile instructions that shall fail */
#define SHALL_COMPILE

class Copyable
{
public:
    Copyable() = default;
    ~Copyable() = default;

    Copyable(const Copyable& rhs) = default;
    Copyable& operator=(const Copyable& rhs) = default; /* Copyable */
};

class MoveOnly
{
public:
    MoveOnly() = default;
    ~MoveOnly() = default;

    MoveOnly(const MoveOnly&) = delete;
    MoveOnly(MoveOnly&& rhs) = default;

    MoveOnly& operator=(const MoveOnly&) = delete;      /* Non Copyable */
    MoveOnly& operator=(MoveOnly&& rhs);                /* Movable */
};

class Unique
{
public:
    Unique() = default;
    ~Unique() = default;

    Unique(const Unique&) = delete;
    Unique(Unique&&) = delete;

    Unique& operator=(const Unique&) = delete;          /* Non Copyable */
    Unique& operator=(Unique&&)= delete;                /* Non Movable */
};

int main()
{
    Copyable copy1;
    MoveOnly move1;
    Unique unique1;

    Copyable copy2 = copy1;
    std::cout << "Copyable copy works" << std::endl;

    Copyable* copy3 = &copy1;
    std::cout << "Copyable move works" << std::endl;

#ifndef SHALL_COMPILE
    MoveOnly move2 = move1;  // BAD - no compile, copy is not allowed */
#else
    std::cout << "MoveOnly copy NOT works" << std::endl;
#endif

    MoveOnly move3 = std::move(move1);
    std::cout << "MoveOnly move works" << std::endl;

#ifndef SHALL_COMPILE
    Unique unique2 = unique1;   // BAD - no compile, copy is not allowed */
#else
    std::cout << "Unique copy NOT works" << std::endl;
#endif

#ifndef SHALL_COMPILE
    Unique unique3 = std::move(unique1);   // BAD - no compile, copy is not allowed */
#else
    std::cout << "Unique move NOT works" << std::endl;
#endif

    return 0;
}

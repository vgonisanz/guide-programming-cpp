#include <iostream>

class Foo
{
public:
  Foo(int foo) : m_foo (foo) {} /* single parameter constructor, can be used as an implicit conversion */
  int get() { return m_foo; }

private:
  int m_foo;
};

class ExplicitFoo
{
public:
  explicit ExplicitFoo(int foo) : m_foo (foo) {}    /* Force explicit */
  int get() { return m_foo; }

private:
  int m_foo;
};

void DoBar(Foo foo)
{
    int i = foo.get();
    std::cout << __func__ << " got value: " << i << " BAD!" << std::endl;
}

void ExplicitDoBar(ExplicitFoo foo)
{
    int i = foo.get();
    std::cout << __func__ << " got value: " << i << " GOOD!" << std::endl;
}


int main()
{
    int value = 42;
    DoBar(value);                       /* BAD - Compile but use in as parameter */
    // ExplicitDoBar(42);               /* BAD - No compile */
    ExplicitDoBar(ExplicitFoo(value));  /* GOOD - Compiler require ExplicitFoo */
    return 0;
}

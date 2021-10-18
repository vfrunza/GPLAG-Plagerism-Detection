#include <iostream>
#include <cctype>
    template<>
    void foo <int> (const int& x)
    {
      // ...implementation details when T is int
      std::cout<<x;
    }

int main()
{
    int x;
    x = foo<>(3);
    std::cout<<x;
    return 0;
}

#include <iostream>

int main()
{
#ifdef AUCA_DEBUG
    std::cout << "author: Bakyt Kudaibergenov\n";
#endif
    std::cout << "Hello, C++ " << __cplusplus << "!\n";
}
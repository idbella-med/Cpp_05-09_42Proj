#include "Base.hpp"

int main()
{
    Base* base = generate();

    std::cout << "Pointer identification: ";
    identify(base);

    std::cout << "Reference identification: ";
    identify(*base);

    delete base;
    return 0;
}
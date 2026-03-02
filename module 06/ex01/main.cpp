#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Omar";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Deserialized pointer: " << newPtr << std::endl;

    if (originalPtr == newPtr)
        std::cout << "Success! Pointers match." << std::endl;
    else
        std::cout << "Error! Pointers do not match." << std::endl;

    return 0;
}
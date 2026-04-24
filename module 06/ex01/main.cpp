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

    std::cout << "Original data: id = " << originalPtr->id << ", name = " << originalPtr->name << std::endl;
    std::cout << "Deserialized data: id = " << newPtr->id << ", name = " << newPtr->name << std::endl;  


    return 0;
}
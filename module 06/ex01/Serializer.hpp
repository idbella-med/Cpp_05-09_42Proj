#pragma once

#include "Data.hpp"


class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer&);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
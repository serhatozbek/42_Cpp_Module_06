#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Gemini";
    myData.value = 3.14f;

    std::cout << "--- Original Data ---" << std::endl;
    std::cout << "Data Address  : " << &myData << std::endl;
    std::cout << "ID            : " << myData.id << std::endl;
    std::cout << "Name          : " << myData.name << std::endl;
    std::cout << "Value         : " << myData.value << std::endl;
    std::cout << "------------------------\n" << std::endl;

    uintptr_t serializedData = Serializer::serialize(&myData);
    std::cout << "Serialized (uintptr_t value): " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized (returned address): " << deserializedData << std::endl;
    std::cout << std::endl;

    if (deserializedData == &myData) {
        std::cout << "SUCCESS: Pointer addresses match!" << std::endl;
        std::cout << "Accessed Data -> ID: " << deserializedData->id
                  << ", Name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "ERROR: Addresses do not match!" << std::endl;
    }

    return 0;
}

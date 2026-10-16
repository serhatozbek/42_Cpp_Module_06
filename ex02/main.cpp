#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int randomValue = std::rand() % 3;

    if (randomValue == 0) {
        std::cout << "--- A class created! ---" << std::endl;
        return new A();
    } else if (randomValue == 1) {
        std::cout << "--- B class created! ---" << std::endl;
        return new B();
    } else {
        std::cout << "--- C class created! ---" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Invalid type !" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {}
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base* obj1 = generate();
    identify(obj1);
    identify(*obj1);
    delete obj1;
    std::cout << std::endl;

    Base* obj2 = generate();
    identify(obj2);
    identify(*obj2);
    delete obj2;
    std::cout << std::endl;

    Base* obj3 = generate();
    identify(obj3);
    identify(*obj3);
    delete obj3;

    return 0;
}

#include "Cat.h"
#include <iostream>

Cat::Cat(const std::string& name, int age, bool isIndoor) 
    : Animal(name, age), isIndoor(isIndoor) {
    std::cout << "Cat constructor: " << name << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor: " << name << std::endl;
}

void Cat::makeSound() const {
    std::cout << name << " says: Meow! Meow!" << std::endl;
}

std::string Cat::getType() const {
    return isIndoor ? "Indoor Cat" : "Outdoor Cat";
}

void Cat::climb() const {
    std::cout << name << " is climbing the tree!" << std::endl;
}

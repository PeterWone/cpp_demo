#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed) 
    : Animal(name, age), breed(breed) {
    std::cout << "Dog constructor: " << name << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor: " << name << std::endl;
}

void Dog::makeSound() const {
    std::cout << name << " says: Woof! Woof!" << std::endl;
}

std::string Dog::getType() const {
    return "Dog (" + breed + ")";
}

void Dog::fetch() const {
    std::cout << name << " is fetching the ball!" << std::endl;
}

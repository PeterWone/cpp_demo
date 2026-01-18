#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& name, int age) : name(name), age(age) {
    std::cout << "Animal constructor: " << name << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor: " << name << std::endl;
}

void Animal::makeSound() const {
    std::cout << name << " makes a generic animal sound" << std::endl;
}

void Animal::introduce() const {
    std::cout << "I am " << name << ", a " << age << " year old " 
              << getType() << std::endl;
}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

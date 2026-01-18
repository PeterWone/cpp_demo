#include "Bird.h"
#include <iostream>
#include <string>

Bird::Bird(const std::string& name, int age, double wingSpan) 
    : Animal(name, age), wingSpan(wingSpan) {
    std::cout << "Bird constructor: " << name << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor: " << name << std::endl;
}

void Bird::makeSound() const {
    std::cout << name << " says: Chirp! Chirp!" << std::endl;
}

std::string Bird::getType() const {
    return "Bird (wingspan: " + std::to_string(wingSpan) + "m)";
}

void Bird::fly() const {
    std::cout << name << " is flying with a wingspan of " 
              << wingSpan << " meters!" << std::endl;
}

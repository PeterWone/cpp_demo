#include <iostream>
#include <vector>
#include <memory>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"

// Function demonstrating polymorphism
void demonstratePolymorphism(const Animal& animal) {
    std::cout << "\n--- Polymorphism Demo ---" << std::endl;
    animal.introduce();
    animal.makeSound();
}

int main() {
    std::cout << "=== C++ Inheritance Demo ===" << std::endl;
    std::cout << "This program demonstrates object-oriented programming concepts:" << std::endl;
    std::cout << "- Inheritance (Animal base class with Dog, Cat, Bird derived classes)" << std::endl;
    std::cout << "- Polymorphism (virtual functions with dynamic dispatch)" << std::endl;
    std::cout << "- Constructors and destructors (notice the call chain)" << std::endl;
    
    std::cout << "\n1. Creating objects (watch constructor chain: base -> derived)...\n" << std::endl;

    // Create derived class objects
    Dog dog("Buddy", 3, "Golden Retriever");
    Cat cat("Whiskers", 2, true);
    Bird bird("Tweety", 1, 0.3);

    std::cout << "\n2. Calling member functions (derived class specific behaviors)...\n" << std::endl;
    
    // Call methods
    dog.introduce();
    dog.makeSound();
    dog.fetch();

    std::cout << std::endl;
    
    cat.introduce();
    cat.makeSound();
    cat.climb();

    std::cout << std::endl;
    
    bird.introduce();
    bird.makeSound();
    bird.fly();

    // Demonstrate polymorphism
    std::cout << "\n3. Polymorphism with references (virtual function calls)...\n" << std::endl;
    std::cout << "Note: Same function, different behavior based on actual object type!" << std::endl;
    demonstratePolymorphism(dog);
    demonstratePolymorphism(cat);
    demonstratePolymorphism(bird);

    // Demonstrate polymorphism with pointers
    std::cout << "\n4. Polymorphism with pointers (using base class pointers to derived objects)...\n" << std::endl;
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("Max", 5, "Labrador"));
    animals.push_back(std::make_unique<Cat>("Luna", 3, false));
    animals.push_back(std::make_unique<Bird>("Sky", 2, 0.5));

    for (const auto& animal : animals) {
        animal->introduce();
        animal->makeSound();
        std::cout << std::endl;
    }

    std::cout << "5. Cleanup phase - objects going out of scope...\n" << std::endl;
    std::cout << "Watch destructor chain: derived -> base (reverse of construction)\n" << std::endl;
    
    return 0;
}

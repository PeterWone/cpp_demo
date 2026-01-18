#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Abstract base class demonstrating inheritance concepts
class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age);
    virtual ~Animal();

    // Virtual function for polymorphism
    virtual void makeSound() const;

    // Pure virtual function - makes this an abstract class
    virtual std::string getType() const = 0;

    // Regular member function
    void introduce() const;

    // Getter methods
    std::string getName() const;
    int getAge() const;
};

#endif // ANIMAL_H

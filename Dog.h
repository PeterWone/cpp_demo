#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <string>

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed);
    ~Dog() override;

    // Override virtual function
    void makeSound() const override;

    // Implement pure virtual function
    std::string getType() const override;

    // Dog-specific method
    void fetch() const;
};

#endif // DOG_H

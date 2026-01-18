#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <string>

class Bird : public Animal {
private:
    double wingSpan;

public:
    Bird(const std::string& name, int age, double wingSpan);
    ~Bird() override;

    // Override virtual function
    void makeSound() const override;

    // Implement pure virtual function
    std::string getType() const override;

    // Bird-specific method
    void fly() const;
};

#endif // BIRD_H

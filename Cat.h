#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <string>

class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat(const std::string& name, int age, bool isIndoor);
    ~Cat() override;

    // Override virtual function
    void makeSound() const override;

    // Implement pure virtual function
    std::string getType() const override;

    // Cat-specific method
    void climb() const;
};

#endif // CAT_H

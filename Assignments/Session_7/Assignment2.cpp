#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    virtual void sound() const = 0;
};

class Mammal : public Animal {
public:
    Mammal(const std::string& n) : Animal(n) {}

    void sound() const override {
        std::cout << "Mammal " << name << " makes a sound" << std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string& n) : Animal(n) {}

    void sound() const override {
        std::cout << "Bird " << name << " makes a sound" << std::endl;
    }
};

class Reptile : public Animal {
public:
    Reptile(const std::string& n) : Animal(n) {}

    void sound() const override {
        std::cout << "Reptile " << name << " makes a sound" << std::endl;
    }
};

int main() {
    Mammal lion("Lion");
    Bird parrot("Parrot");
    Reptile snake("Snake");

    lion.sound();
    parrot.sound();
    snake.sound();

    return 0;
}

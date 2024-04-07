#include <iostream>

#include <memory>

class Animal
{

public:

    virtual ~Animal(){};
    virtual void makeSound() = 0;
};

class Dog : public Animal
{

public:
    void makeSound() override
    {
        std::cout <<"Woof Woof"<<std::endl;
    }

};

class Cat : public Animal
{
public:
    ~Cat()
    {
        std::cout<<"~Cat()"<<std::endl;
    }


    void makeSound() override
    {
        std::cout <<"Meow"<<std::endl;
    }

};

class Bird : public Animal
{
public:
    void makeSound() override
    {
        std::cout <<"Tweet Tweet"<<std::endl;
    }
};


int main()
{

    {
    
    Animal *animal1 = new Cat();
    Animal *animal2 = new Dog();
    Animal *animal3 = new Bird();


    
    std::unique_ptr<Animal> ptr  =  std::make_unique<Cat>();

    animal1->makeSound();
    animal2->makeSound();
    animal3->makeSound();

    
    }



}
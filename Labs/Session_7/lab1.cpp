#include <iostream>

class Shape
{
public:

    Shape(){}

    virtual ~Shape()
    {
        std::cout << "~Shape()"<<std::endl;
    }


    virtual void calcArea()
    {

    };

};

class Circle : public Shape
{
    float diameter;

public:

    Circle(float d) : diameter{d}{};

    ~Circle()
    {
        std::cout<<"~Circle()"<<std::endl;
    }

    void calcArea()
    {
        std::cout << "Area of circle is: " << diameter * 3.14<<std::endl;
    }
};

class Rectangle : public Shape
{
    int length;
    int width;
public:

    Rectangle(int l, int w) : length{l}, width{w}{}

    ~Rectangle()
    {
        std::cout<<"~Rectangle()"<<std::endl;
    }

    void calcArea()
    {
        std::cout <<"Area of Rectangle is : " << length * width << std::endl;
    }
};

int main()
{
 

   
    Shape *sh1 = new Circle(22);
    Shape *sh2 = new Rectangle(3,3);

    sh1->calcArea();
    sh2->calcArea();

    delete sh1;
    delete sh2;

    

    return 0;
}
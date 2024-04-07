#include <iostream>
#include <cmath>
#include <string>

class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& col) : color(col) {}
    
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const std::string& col, double w, double h) : Shape(col), width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& col, double r) : Shape(col), radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double base;
    double triHeight;

public:
    Triangle(const std::string& col, double b, double h) : Shape(col), base(b), triHeight(h) {}

    double getArea() const override {
        return 0.5 * base * triHeight;
    }
};

int main() {
    Rectangle rect("Blue", 5.0, 4.0); // Color, Width, Height
    Circle circle("Red", 3.0); // Color, Radius
    Triangle triangle("Green", 4.0, 6.0); // Color, Base, Height

    std::cout << "Rectangle Area: " << rect.getArea() << std::endl;
    std::cout << "Circle Area: " << circle.getArea() << std::endl;
    std::cout << "Triangle Area: " << triangle.getArea() << std::endl;

    return 0;
}

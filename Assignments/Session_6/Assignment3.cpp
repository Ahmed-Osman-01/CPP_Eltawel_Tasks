#include <iostream>
#include <string>
#include <cmath>

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& n) : name(n) {}
    
    std::string getName() const {
        return name;
    }
    
    virtual double calculateArea() const = 0;
    virtual double calculateVolume() const = 0;
};

class TwoDimensionalShape : public Shape {
public:
    TwoDimensionalShape(const std::string& n) : Shape(n) {}
};

class Rectangle : public TwoDimensionalShape {
private:
    double length;
    double width;

public:
    Rectangle(const std::string& n, double l, double w) : TwoDimensionalShape(n), length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }
    
    double calculateVolume() const override {
        return 0.0; // Rectangles are 2D shapes, so their volume is 0
    }
};

class Circle : public TwoDimensionalShape {
private:
    double radius;

public:
    Circle(const std::string& n, double r) : TwoDimensionalShape(n), radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double calculateVolume() const override {
        return 0.0; // Circles are 2D shapes, so their volume is 0
    }
};

class Triangle : public TwoDimensionalShape {
private:
    double base;
    double height;

public:
    Triangle(const std::string& n, double b, double h) : TwoDimensionalShape(n), base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
    
    double calculateVolume() const override {
        return 0.0; // Triangles are 2D shapes, so their volume is 0
    }
};

class ThreeDimensionalShape : public Shape {
public:
    ThreeDimensionalShape(const std::string& n) : Shape(n) {}
    
    virtual double calculateVolume() const = 0;
};

class Sphere : public ThreeDimensionalShape {
private:
    double radius;

public:
    Sphere(const std::string& n, double r) : ThreeDimensionalShape(n), radius(r) {}

    double calculateArea() const override {
        return 4 * 3.14159 * radius * radius;
    }
    
    double calculateVolume() const override {
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
    }
};

int main() {
    Rectangle rectangle("Rectangle", 5.0, 4.0);
    Circle circle("Circle", 3.0);
    Triangle triangle("Triangle", 4.0, 6.0);
    Sphere sphere("Sphere", 3.0);

    std::cout << "Shape: " << rectangle.getName() << ", Area: " << rectangle.calculateArea() << ", Volume: " << rectangle.calculateVolume() << std::endl;
    std::cout << "Shape: " << circle.getName() << ", Area: " << circle.calculateArea() << ", Volume: " << circle.calculateVolume() << std::endl;
    std::cout << "Shape: " << triangle.getName() << ", Area: " << triangle.calculateArea() << ", Volume: " << triangle.calculateVolume() << std::endl;
    std::cout << "Shape: " << sphere.getName() << ", Area: " << sphere.calculateArea() << ", Volume: " << sphere.calculateVolume() << std::endl;

    return 0;
}

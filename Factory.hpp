#include <iostream>
#include <memory>

class Shape
{
    public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
    public:
    void draw() override {std::cout << "Drawing Circle" << std::endl;}
};

class Rectangle : public Shape
{
    public:
    void draw() override {std::cout << "Drawing Rectangle" << std::endl;}
};

class ShapeFactory
{
    public:
    static std::shared_ptr<Shape> creatShape(const std::string& type)
    {
        if(type == "Circle") return std::make_shared<Circle>();
        if(type == "Rectangle") return std::make_shared<Rectangle>();
        return nullptr; 
    }
};
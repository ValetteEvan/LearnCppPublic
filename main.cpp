#include <iostream>
#include <memory>
#include <ostream>

#include "Singleton.hpp"
#include "Factory.hpp"
#include "Structural.hpp" 

template<typename T>
T add(T a,T b)
{
    return a + b;
}

template<typename T>
class Box 
{
    T value;
    public:
    Box(T _value) : value(_value) {} 
    T getValue()const {return value;}
};

template<>
class Box<int>
{
    int value;
    public:
    Box(int _value) : value(_value) {} 
    int getValue()const {return value;}
    void printTypeOfValue() {std::cout << "Integer" << std::endl;}
};

template<>
class Box<float>
{
    float value;
    public:
    Box(float _value) : value(_value) {} 
    float getValue()const {return value;}
    void printTypeOfValue() {std::cout << "Float" << std::endl;}
};
template<typename T>
std::ostream& operator<<(std::ostream& os,const Box<T>& box)
{
    os << box.getValue();
    return os;
}

template<typename... Args> 
void printf(Args... args)
{
    (std::cout << ... << args) << std::endl; 
}

int main()
{
  /* Box<int> boxInt(5);
  std::cout << boxInt.getValue() << std::endl;
  boxInt.printTypeOfValue();

  Box<float> boxFloat(23.788);
  std::cout << boxFloat.getValue() << std::endl;
  boxFloat.printTypeOfValue();  

  Box<std::string> boxString("Hello");
  std::cout << boxString.getValue() << std::endl;

  printf(boxString,"-",boxFloat,"-",boxInt);*/

    //Singleton exemple basic 
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    //Factory basic exemple
    auto circle = ShapeFactory::creatShape("Circle");
    auto rectangle = ShapeFactory::creatShape("Rectangle");
    circle->draw(); 
    rectangle->draw();

    //Structural basic exemple
    OldPrinter oldPrinter;
    PrinterAdapter adapter(&oldPrinter);

    adapter.print();

    return 0;
}
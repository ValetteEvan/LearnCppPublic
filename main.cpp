#include <iostream>
#include <memory>
#include <ostream>

#include "Singleton.hpp"
#include "Factory.hpp"
#include "Structural.hpp" 
#include "Composite.hpp"
#include "Behavioral.hpp" 

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

    //Composite basic exemple

    //documents
    auto leaf1 = std::make_shared<Leaf>();
    auto leaf2 = std::make_shared<Leaf>();

    //folder
    auto composite = std::make_shared<Composite>();

    //Add many documents on folder
    composite->add(leaf1);
    composite->add(leaf2);

    composite->operation();

    //Behaviaral basic exemple
    //Channel message
    auto subject  = std::make_shared<Subject>();
    //Create user and name
    auto observer1 = std::make_shared<ConcreteObserver>("Observer1");
    auto observer2 = std::make_shared<ConcreteObserver>("Observer2");

    //Add user on channel
    subject->addObserver(observer1);
    subject->addObserver(observer2);

    //Send message for all user
    subject->notifyObservers(" Hello everyone");

    return 0;
}
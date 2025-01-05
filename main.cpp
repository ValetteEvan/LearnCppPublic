#include <iostream>
#include <memory>
#include <ostream>

#include "Template.hpp"
#include "Singleton.hpp"
#include "Factory.hpp"
#include "Structural.hpp" 
#include "Composite.hpp"
#include "Behavioral.hpp" 

#include "ClassLearn.hpp"

int main()
{
    //Test application template basic 
    Box<int> boxInt(5);
    std::cout << boxInt.getValue() << std::endl;
    boxInt.printTypeOfValue();

    Box<float> boxFloat(23.788);
    std::cout << boxFloat.getValue() << std::endl;
    boxFloat.printTypeOfValue();  

    Box<std::string> boxString("Hello");
    std::cout << boxString.getValue() << std::endl;

    printf(boxString,"-",boxFloat,"-",boxInt);

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

    std::cout << "------------------" << std::endl;

    Test::printOnConsole();
    int a = Test::returnStaticValue();
    std::cout << a << std::endl;

    return 0;
}
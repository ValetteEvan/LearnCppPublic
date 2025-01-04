#include <iostream>
#include <vector>
#include <memory>

class Observer 
{
    public:
    virtual void update(const std::string& message) = 0;
};

class Subject 
{
    std::vector<std::shared_ptr<Observer>> observers;
    
    public:
    void addObserver(const std::shared_ptr<Observer>& observer) 
    {
        observers.push_back(observer);
    }  
    void notifyObservers(const std::string& message)
    {
        for(auto& observer : observers)
        {
            observer->update(message);
        }
    }
};

class ConcreteObserver : public Observer
{
    std::string name;
    
    public:
    ConcreteObserver(const std::string& name) : name(name) {}
    void update(const std::string& message) override
    {
        std::cout << "Observer" << name << "Received message" << message << std::endl;
    }
};




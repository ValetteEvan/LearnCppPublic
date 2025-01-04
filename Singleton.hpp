#include <iostream>

class Singleton 
{
    private:
    //unique instance 
    static Singleton* instance; 
    //private constructor
    Singleton() {}

    public:
    static Singleton* getInstance()
    {
        if(!instance)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {std::cout << "Singleton Instance" << std::endl;}
};

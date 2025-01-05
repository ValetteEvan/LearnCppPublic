#include <iostream>
#include <ostream>

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
#include <iostream>

using namespace std;

class Test
{
    private:
    int value;
    static int staticValue;
    public:
    Test() = default;
    static void printOnConsole() {cout << "Test on console" << endl;}
    static int returnStaticValue() {return staticValue;}
};

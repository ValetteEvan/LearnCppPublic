#include <iostream>

class OldPrinter
{
    public:
    void oldPrint() {std::cout << "Printing using old printer" <<std::endl;}
};

class NewPrinter
{
    public:
    virtual void print() = 0;
};

class PrinterAdapter : public NewPrinter
{
    OldPrinter* oldPrinter;
    public:
    PrinterAdapter(OldPrinter* printer) : oldPrinter(printer) {}
    void print() override {oldPrinter->oldPrint();}
};
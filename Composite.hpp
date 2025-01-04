#include <iostream>
#include <memory>
#include <vector>
#include <memory.h>

class Component
{
    public:
    virtual void operation() = 0;
    virtual ~Component() = default;
};

class Leaf : public Component
{
    public:
    void operation() override {std::cout << "Leaf operation" << std::endl;}
};
class Composite : public Component
{
    std::vector<std::shared_ptr<Component>> children;

    public:
    void add(const std::shared_ptr<Component>& component) {children.push_back(component);}
    void operation() override 
    {
        for(const auto& child : children)
        {
            child->operation();
        }
    }
};

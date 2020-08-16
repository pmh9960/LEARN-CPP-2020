#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name;
    Example m_Example;

public:
    // Entity()
    // {
    //     m_Name = "Unknown";
    //     m_Example = Example(10);
    // }
    Entity()
        : m_Name("Unknown"), m_Example(10) // or m_Example(Example(8))
    {
        // You have to write the initializer list in the same order as declared.
    }
    Entity(const std::string &name)
        : m_Name(name)
    {
    }

    const std::string GetName() const { return m_Name; }
};

int main()
{
    // Entity e0;
    // std::cout << e0.GetName() << std::endl;

    // Entity e1("Minho");
    // std::cout << e1.GetName() << std::endl;

    Entity ex;
}
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity &e)
{
}

int main()
{

    Entity e1 = std::string("Minho"); // implicit
    // Entity e2 = 22;                   // implicit

    PrintEntity(std::string("Minho")); // implicit
    // PrintEntity(22);                   // implicit

    Entity e3("Minho"); // explicit
    Entity e4(22);      // explicit
}
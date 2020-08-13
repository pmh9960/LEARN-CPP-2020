#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0; // Pure virtual function
    // Everything which inherit "Pure virtual function" should have the function
    // If not you cannot instantiate it
};

class Entity : public Printable
{
public:
    // std::string GetName() { return "Entity"; }
    virtual std::string GetName() { return "Entity"; } // Generate the V-table
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name)
        : m_Name(name) {}

    // std::string GetName() { return m_Name; } // Override GetName function
    std::string GetName() override { return m_Name; } // Override GetName function
                                                      // Writing override is not necessary but it makes readable,
                                                      // and helps to find override error.

    std::string GetClassName() override { return "Player"; }
};
void Print(Printable *obj)
{
    std::cout << obj->GetClassName() << std::endl;
}
void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl; // Just call Entity::GetName function (If Not the Virtual function)
}

int main()
{
    Entity *e = new Entity();
    Player *p = new Player("Mino");
    PrintName(e);                           // Entity
    std::cout << p->GetName() << std::endl; // Mino
    PrintName(p);                           // Entity (?) -> override : Mino (Work well)

    // Additional Memory for V-Table.
    // Additional time cost for searching in V-Table.
    // However, these cost is not too large to feel.

    // * Pure virtual function
    Print(e);
    Print(p);

    return 0;
}
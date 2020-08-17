#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}
    Entity(const String &name) : m_Name(name) {}

    const String &GetName() const { return m_Name; }
};

int main()
{
    Entity *e;
    {
        // Entity entity("Minho"); // Stack
        // e = &entity;
        Entity *entity = new Entity("Minho"); // Heap
        e = entity;
        std::cout << e->GetName() << std::endl;
    }

    std::cout << e->GetName() << std::endl; // Stack : error, Heap : ok
    delete e;                               // The pointer of Heap allocation needs manually being freed memory.
    return 0;
}
#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

// int *CreateArrayFalse()
// {
//     int array[50];
//     return array; // Not work, because of scope
// }

int *CreateArray()
{
    int *array = new int[50];
    return array; // Work
}

class ScopedPtr
{
private:
    Entity *m_Ptr;

public:
    ScopedPtr(Entity *ptr) : m_Ptr(ptr) {}
    ~ScopedPtr() { delete m_Ptr; }
};

int main()
{
    // Entity e;               // Destroyed at the end of the scope
    // Entity *e = new Entity; // does not be destroyed before delete keyword

    {
        ScopedPtr e = new Entity();
    } // This is the basic 'smart pointer'
}
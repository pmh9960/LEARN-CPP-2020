#include <iostream>

class Entity
{
private:
    int m_X, m_Y;
    int *m_Pointer;

    // cf. How to declare multiple pointers in one-line.
    // int *m_X, *m_Y; // Attach '*' to every variable.

    mutable int var;

public:
    Entity()
    {
        m_X = 2;
        m_Y = 3;
        m_Pointer = new int;
    }

    int GetX() const
    {
        // m_X = 2; // error
        var = 2; // mutable keyword ignore const keyword
        return m_X;
    }

    const int *const GetPointer() const
    {
        return m_Pointer;
    } // We can use const like this way too.
      // This means we don't change anything of the pointer.
};

void PrintEntityX(const Entity &e)
{
    std::cout << e.GetX() << std::endl;
    // If GetX method is not const function, we can't call the method.
    // Because there is no guarantee of that 'e' which is const variable doesn't be changed
}

int main()
{
    Entity e;
    PrintEntityX(e);
}
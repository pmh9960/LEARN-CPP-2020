#include <iostream>

class Entity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

// Inheritance convert Visibility which is wider than declared to declared Visibility.
// Ex) class Player : private Entity
// This declare convert all protected, public members PRIVATE.
// Therefore, public doesn't change any member.

class Player : public Entity
{
public:
    const char *Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Entity) << std::endl; // 8
    std::cout << sizeof(Player) << std::endl; // 16
    // sizeof(pointer)
    // 32-bit system = 4
    // 64-bit system = 8 (My case)

    return 0;
}
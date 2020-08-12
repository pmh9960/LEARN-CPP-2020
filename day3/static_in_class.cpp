#include <iostream>

struct Entity
{
    // int x, y; // Normal way
    // static int x, y; // Type 1, 2
    int x, y; // Type 3, 4

    // void Print()
    // {
    //     std::cout << x << ", " << y << std::endl;
    // } // Normal, Type 1

    // Static function can't call non-static variables!
    // static void Print()
    // {
    //     std::cout << x << ", " << y << std::endl;
    // } // Type 2, 3
};

static void Print(Entity e)
{
    std::cout << e.x << ", " << e.y << std::endl;

    return;
} // Type 4

// Static variables share their value
// int Entity::x; // Type 1, 2
// int Entity::y; // Type 1, 2

int main()
{
    Entity e1;
    e1.x = 2;
    e1.y = 3;
    // Entity::x = 2; // Type 1
    // Entity::y = 3; // Type 1

    Entity e2;
    e2.x = 5;
    e2.y = 8;
    // Entity::x = 5; // Type 1
    // Entity::y = 8; // Type 1

    // e1.Print(); // Normal, Type 1
    // Normal way : 2, 3
    // Type 1     : 5, 8
    // e2.Print(); // Normal, Type 1
    // Normal way : 5, 8
    // Type 1     : 5, 8

    // Entity::Print(); // Type 2
    // Entity::Print(); // Type 2

    Print(e1); // Type 4
    Print(e2); // Type 4

    return 0;
}
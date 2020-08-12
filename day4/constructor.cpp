#include <iostream>

class Entity
{
public:
    float e_X, e_Y;

    Entity() // Constructor 1
    {
        std::cout << "Constructed Entity! with C1" << std::endl;
        e_X = 0;
        e_Y = 0;
    }
    Entity(float x, float y) // Constructor 2 (Args)
    {
        std::cout << "Constructed Entity! with C2" << std::endl;
        e_X = x;
        e_Y = y;
    } // You can make both constructors at the same time.
    // Entity() = delete; // Special constructor

    ~Entity() // Destructor
    {
        std::cout << "Destructed Entity!" << std::endl;
    }

    void Print()
    {
        std::cout << e_X << ", " << e_Y << std::endl;
    }
};

int main()
{

    {
        Entity e(10.0f, 5.0f);
        e.Print();
    } // Desturctor works when life of Entity is over.
    std::cin.get();

    return 0;
}
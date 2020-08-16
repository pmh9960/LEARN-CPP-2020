#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;

public:
    const std::string getName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    Entity e;
    std::cout << e.getName() << std::endl;

    // Lambda
    int x = 8;
    auto f = [=]() mutable {
        x++;
        std::cout << x << std::endl;
    };
    f();
    std::cout << x << std::endl; // x = 8
}
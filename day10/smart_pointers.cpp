#include <iostream>
#include <memory>

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

int main()
{

    std::cout << "Unique pointer" << std::endl;
    {
        // std::unique_ptr<Entity> entity1 = new Entity(); // You can't use implicit way
        std::unique_ptr<Entity> entity2(new Entity());                // Normal way
        std::unique_ptr<Entity> entity3 = std::make_unique<Entity>(); // Recommened way
    }
    std::cout << std::endl;

    std::cout << "Shared pointer & Weak pointer" << std::endl;
    {
        std::shared_ptr<Entity> e;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            std::weak_ptr<Entity> weakEntity = sharedEntity;
            e = sharedEntity;
        }
        // sharedEntity is dead, but the pointer still alive.
        std::cout << "Shared pointer still alive!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Weak pointer" << std::endl;
    {
        std::weak_ptr<Entity> weakEntity;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            weakEntity = sharedEntity;
        }
        std::cout << "sharedEntity is dead" << std::endl;
    }
}
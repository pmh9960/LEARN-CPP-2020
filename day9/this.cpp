#include <iostream>

void PrintEntity(const Entity &e);

class Entity
{
private:
    int x, y;

public:
    Entity(int x, int y)
    {
        this; // Entity *const
        this->x = x;
        this->y = y;

        PrintEntity(*this); // We can also use this like this.
    }

    void function() const
    {
        this; // const Entity *const
        // Entity *e = this;      // error
        const Entity *e = this; // good
    }
};

void function(int x, int y)
{
    int k;
}

int main()
{
    int *const a = new int;
    *a = 10;
}
#include <iostream>

struct Vector2
{
    float x, y;
    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 Multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return Add(other);
    }
    Vector2 operator*(const Vector2 &other) const
    {
        return Multiply(other);
    }

    // more example
    bool operator==(const Vector2 &other) const
    {
        return (x == other.x) && (y == other.y);
    }
    bool operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }
};

std::ostream &operator<<(std::ostream &stream, Vector2 &other)
{
    stream << other.x << ", " << other.y; // Isn't it weird? We overload << operator!
    return stream;
}

int main()
{
    Vector2 position(1.0f, 2.0f);
    Vector2 speed(0.5f, 1.0f);
    Vector2 powerup(1.1f, 1.3f);

    Vector2 result1 = position.Add(speed.Multiply(powerup)); // Ugly
    Vector2 result2 = position + speed * powerup;
    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
    if (result1 == result2)
        std::cout << "Both are same!" << std::endl;
    else
        std::cout << "Both are different!" << std::endl;
}
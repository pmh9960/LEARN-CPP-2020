# Day 9

## [Operator](operator.cpp)

- Operator is just a function in this day.

- Some operators need overloading in `sturct` of `class` for clean code.

1. Use a function

   ```cpp
   Vector2 result1 = position.Add(speed.Multiply(powerup));
   ```

1. Use an operator
   ```cpp
   Vector2 result2 = position + speed * powerup;
   ```

To write like second way, we should overload `+` and `*` operator.

1. Declare an operator with defined function

   ```cpp
   Vector2 Add(const Vector2 &other) const
   {
       return Vector2(x + other.x, y + other.y);
   }

   Vector2 operator+(const Vector2 &other) const
   {
       return Add(other);
   }
   ```

1. A simple operator doesn't need a function.

   ```cpp
   Vector2 operator+(const Vector2 &other) const
   {
       return Vector2(x + other.x, y + other.y);
   }
   Vector2 Add(const Vector2 &other) const
   {
       return *this + other;
   }
   ```

   In addition, we can declare a function with the declared operator.

- `<<` operator have to redefine, too.

  It is not the operator that operate with sturctures.

  Thus, we declare `<<` operator out of the `Vector2` structure.

  ```cpp
  std::ostream &operator<<(std::ostream &stream, Vector2 &other)
  {
      stream << other.x << ", " << other.y; // Isn't it weird? We overload << operator!
      return stream;
  }
  ```

## [`this` keyword](this.cpp)

- `this` keyword point the entity of the `class / sturct`.

  We can use `this` to distinguish between members and arguments.

  ```cpp
  class Entity
  {
  private:
      int x, y;

  public:
      Entity(int x, int y)
      {
          this->x = x;
          this->y = y;
      }
  };
  ```

- Basically, `this` is `const address` pointer (i.e. `Entity *const`)

  We can't modify the address of the pointer.

  If the method is `const` method, `this` will be `const Entity *const`.

  Therefore, we can not change the value, and also can not decalre with non-const variable.

  ```cpp
  Entity *e = this;       // error
  const Entity *e = this; // good
  ```

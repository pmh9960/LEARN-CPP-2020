# Day 8

## Create/Instantiate objects

- Allocate on the stack

  The basic way to allocate data in the memory.

  The allocated data will be destroyed after end curly bracket, such as local variables.

  ```cpp
  Entity entity("Minho"); // Stack
  ```

- Allocate on the heap

  Data allocated in the heap must be freed manually.

## The `new` keyword

- `new` returns a pointer.

- `new` does not only allocate the memory, but also calls constructor.

- `new` is operator.

- `new` vs. `malloc`

  `malloc` purely allocates memory (Use in C), `new` also calls constructor.

  `delete` vs. `free` have same relation.

  ```cpp
  Entity *e1 = new Entity();
  Entity *e2 = (Entity *)malloc(sizeof(Entity));
  ```

## Implicit conversion and Explicit keyword

C++ has implicit conversion which makes some deviations work.

```cpp
// Constructor part in Entity class
Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
Entity(int age) : m_Name("Unknown"), m_Age(age) {}

// Declare part
Entity e1 = std::string("Minho");
Entity e2 = 22;
```

However there is `explicit` keyword which makes that users can't use implicit syntax.

```cpp
explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}

Entity e3("Minho"); // explicit, but it is also called implicit
Entity e4(22);      // explicit

Entity e5 = 22;     // ERROR
```

On the Entity e1 line, there is implicit conversion. (`const char [6]` to `std::string`)

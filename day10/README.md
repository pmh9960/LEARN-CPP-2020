# Day 10

## Table of Contents

1. [Stack and scope](#stack-and-scope)

   - [code](stack_and_scope.cpp)

1. [Smart pointers](#smart-pointers)

   - [code](smart_pointers.cpp)

1. [Copying and Copy Constructors](#copying-and-copy-constructors)

   - [code](copy_constructors.cpp)

1. [cf. `friend` keyword](#cf-friend-keyword)

## Stack and scope

_There are two kind of memory. **Heap** and **Stack**_

_Lifetime of both are different._

- Stack

  We store in stack when we declare a variable in ordinary way.

  - Scope / Lifetime

    The lifetime of stack memory is same as scope.

    Scope also means curly braket in C++ (`{ }`)

    ```cpp
    {
        Entity e;
    } // end of the scope
    ```

    Result

    ```
    Created Entity!
    Destroyed Entity!
    ```

- Heap

  If we declare a variable with `new`, the variable will stored in Heap memory.

  - Scope / Lifetime

    The lifetime of heap memory does not depend on scope.

    Its lifetime is end when `delete` keyword appear.

    ```cpp
    {
        Entity *e = new Entity;
    }
    ```

    Result

    ```
    Created Entity!
    ```

  You may also reference this idea.

  ```cpp
  int *CreateArrayFalse()
  {
    int array[50];
    return array; // Not work, because of scope
  }
  ```

  ```cpp
  int *CreateArray()
  {
    int *array = new int[50];
    return array; // Work
  }
  ```

- Basic smart pointer

  ```cpp
  class ScopedPtr
  {
  private:
      Entity *m_Ptr;

  public:
      ScopedPtr(Entity *ptr) : m_Ptr(ptr) {}
      ~ScopedPtr() { delete m_Ptr; }
  };
  ```

  ```cpp
  {
      ScopedPtr e = new Entity();
  }
  ```

  Result

  ```
  Created Entity!
  Destroyed Entity!
  ```

  The entity is also destroyed even though heap allocation.

## Smart pointers

> There are 3 smart pointers.
>
> We have to prefer these pointers rather than raw pointers.
> First, use unique pointer as you can, then use shared pointer if you have to share it.
>
> These smart pointers can't replace all parts of `new` and `delete`, and also it has some overhead.
> However, the advantage is that we don't have to care memory management. (i.e. **_Smart pointers prevent the forget of `delete`._**)

1. Unique pointer (`std::unique_ptr`)

   You can't copy this pointer, because it is unique

   - How to create

     ```cpp
     std::unique_ptr<Entity> entity2(new Entity());                // Normal way
     std::unique_ptr<Entity> entity3 = std::make_unique<Entity>(); // Recommened way
     ```

     You can't use implicit way. Its constructor is explicit.

     ```cpp
     std::unique_ptr<Entity> entity1 = new Entity(); // error
     ```

1. Shared pointer (`std::shared_ptr`)

   Unique pointer can't share the pointer, but shared pointer can.

   Shared pointer uses reference counter which counts how many shared pointer live.

   If reference counter equals to zero, the shared pointer die.

   _Shared pointer dies when all of the pointers dead._

   ```cpp
   {
       std::shared_ptr<Entity> e;
       {
           std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
           e = sharedEntity;
       }
       // sharedEntity is dead, but the pointer still alive.
       std::cout << "Shared pointer still alive!" << std::endl;
   }
   std::cout << std::endl;
   ```

   Result

   ```cpp
   Created Entity!
   Shared pointer still alive!
   Destroyed Entity!
   ```

1. (`std::weak_ptr`)

   Weak pointer is similar with shared pointer, but weak pointer does not increase reference counter.

   Example 1. Weak pointer also can share pointer with shared pointer.

   ```cpp
   std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
   std::weak_ptr<Entity> weakEntity = sharedEntity;
   ```

   Example 2. Weak pointer does not increas reference counter.

   ```cpp
   std::cout << "Weak pointer" << std::endl;
   {
       std::weak_ptr<Entity> weakEntity;
       {
           std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
           weakEntity = sharedEntity;
       }
       std::cout << "sharedEntity is dead" << std::endl;
   }
   ```

## Copying and Copy Constructors

- Common copy example

  ```cpp
  int a = 3;
  int b = a;
  b = 2; // 'a' does not change
  ```

  ```cpp
  int *a = new int;
  (*a) = 3;
  int *b = a;
  (*b) = 2; // both are changed
  ```

- Without copy constructor

  Basic String class

  ```cpp
  class String
  {
  private:
      char *m_Buffer;
      unsigned int m_Size;

  public:
      String(const char *string)
      {
          m_Size = strlen(string);
          m_Buffer = new char[m_Size + 1];
          memcpy(m_Buffer, string, m_Size);
          m_Buffer[m_Size] = 0;
      }
      ~String()
      {
          delete m_Buffer;
      }
  };
  ```

  If we do copy formal way, the `m_Buffer` is deleted twice.

  ```cpp
  String string("Minho");
  String second = string; // error when the deconsturctor of second works.
  ```

  Below statement is what consturctor does, when there is no copy constructor.

  ```cpp
  String(const String &other)
  {
      memcpy(this, &other, sizeof(String));
  }
  ```

- There is 2 solutions that fix this problem

1. Make String class like unique pointer.

   ```cpp
   String(const String &other) = delete; // Looks like unique pointer.
   ```

   Then, you can't copy this class.

1. Make **Copy Constructor**.

   ```cpp
   String(const String &other)
   {
       std::cout << "Copied String!" << std::endl;
       m_Size = other.m_Size;
       m_Buffer = new char[m_Size + 1];
       memcpy(m_Buffer, other.m_Buffer, m_Size);
       m_Buffer[m_Size] = 0;
   }
   ```

- cf. why _const reference_ needs

  - Example 1. This function copy String everytime when the fucntion is called.

    ```cpp
    void PrintCopiedString(String string)
    {
        std::cout << string << std::endl;
    }
    ```

    Result

    ```
    Copied String!
    Copied String!
    Minho
    Copied String!
    Mimho
    ```

    It repeats `Copied String!` 3 times.

  - Example 2. Recommended way

    ```cpp
    void PrintString(const String &string)
    {
        std::cout << string << std::endl;
    }
    ```

    Result

    ```
    Copied String!
    Minho
    Mimho
    ```

    It repeats `Copied String!` only one time, because the `PrintString` function doesn't copy String.

## cf. `friend` keyword

We can use private members out of the class, if we declare the function as friend in class like this.

```cpp
friend void exampleFunction();
```

In real example, we use private member(`m_Buffer`) in `std::ostream &operator<<` which is out of the class.

```cpp
class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    ...

    friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffer;
    return stream;
}
```

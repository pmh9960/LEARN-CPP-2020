# Day 7

## Constant keyward (`const`)

`const` is a fake keyword. It doesn't do anything. In most cases, the role of `const` is just a promiss.

- Constant variable

  We can't change a value of the variable.

  ```cpp
  const int MAX_AGE = 90;
  ```

- Constant pointer

  - `const int *` (`int const *`)

    We can't change the contents of the pointer

    ```cpp
    const int *b = new int;
    *b = 2; // error
    b = (int *)&MAX_AGE;
    std::cout << *b << std::endl;
    ```

  - `int* const`

    We can't change the address of the pointer

    ```cpp
    int *const c = new int;
    *c = 2;
    c = (int *)&MAX_AGE; // error
    std::cout << *c << std::endl;
    ```

## Const in Class

When we use `const` after the function, it means the function doesn't change any member of the class.

```cpp
int GetX() const
{
    m_X = 2; // error
    return m_X;
}
```

- Is this just a promiss, too? **NO**

  ```cpp
  void PrintEntityX(const Entity &e)
  {
      std::cout << e.GetX() << std::endl;
  }
  ```

  If GetX method is not a const function, we can't call the method.

  The reason is there is no guarantee of a **const variable `e`** will not change.

  Therefore, it makes error.

## Mutable keyword (`mutable`)

`mutable` is the opposite keyword of `const`.

- `mutable` ignore `const`

  ```cpp
  private:
      int m_X, m_Y;
      mutable int var;

  public:
      int GetX() const
      {
          // m_X = 2; // error
          var = 2;    // not error
          return m_X;
      }
  ```

- `mutable` also use with `lambda`

  ```cpp
  int x = 8;
  auto f = [=]() mutable {
      x++;
      std::cout << x << std::endl;
  };
  f();
  // x = 8 (unchanged)
  ```

## Member initializer list

- Why use?

  1. Clean up the code

     If we don't use Member initializer list, the most of constructor will be filled initialize.

     It doesn't help to check what constructor do.

  1. Functional difference

     Without initializer list, compiler makes extra memory to save the arguments in initialize process. It waste a performance.

- How use?

  1. Formal way

     ```cpp
     Entity::Entity()
     {
         m_Name = "Unknown";
         m_Example = Example(10);
     }
     Entity::Entity(const std::string &name)
     {
         m_Name = name;
     }
     ```

  1. Member initializer list

     You may write the initializer list in the same order as declared, because some compiler could warn about that.

     ```cpp
     Entity()
         : m_Name("Unknown"), m_Example(10) // or m_Example(Example(8))
     {
         // You have to write the initializer list in the same order as declared.
     }
     Entity::Entity(const std::string &name)
         : m_Name(name)
     {
     }
     ```

  - cf. Example class

    ```cpp
    class Example
    {
    public:
        Example()
        {
            std::cout << "Created Entity!" << std::endl;
        }
        Example(int x)
        {
            std::cout << "Created Entity with " << x << "!" << std::endl;
        }
    };
    ```

  - Result

    1. Formal way : Create entity 2 times.

       ```
       Created Entity!
       Created Entity with 10!
       ```

    1. Member initializer list : Create entity only 1 time.

       ```
       Created Entity with 10!
       ```

       Therefore, Member initializer list save performance.

## Ternary operation

Ternary operation is same as if-else statement, but it is cleaner (subjective) and little bit faster.

- Ordinary form

  ```cpp
  result = op ? a : b;
  ```

  is same as

  ```cpp
  if (op)
      result = a;
  else
      result = b;
  ```

- [C++ | Nested Ternary Operator](https://www.geeksforgeeks.org/c-nested-ternary-operator/)

1. `result = a ? b: c ? d : e ? f : g ? h : i;`

   ```cpp
   if a then b
       else if c then d
       else if e then f
       else if g then h
       else i
   ```

1. `result = a ? b ? c : d : e;`

   ```cpp
   if ( a )
       if ( b )
           c execute
       else
           d execute
   else
       e execute
   ```

## cf. How to declare multiple pointers in one-line.

Attach '\*' to every variable.

```cpp
int *m_X, *m_Y;
```

## cf. Lambda

Lambda is a simple function maker.

Lambda also needs arguments to use any variable which is out of lambda. Therefore, we have to write the variables on capture list.

```cpp
auto f = []() {}; // There is no introducer
auto f = [x]() {}; // x is in the introducer
auto f = [&]() {}; // All of the variable reference (not copy) in the lambda. We can change the value of the variable.
auto f = [=]() {}; // All of the vairable reference as const. We can't change the value of the variable.
auto f = [=]() mutable {}; // The value is mutalbe, but the variable which is captured cannot change.
```

- more info : [모두의 코드, 씹어먹는 C++ 토막글 ② - 람다(lambda) 함수](https://modoocode.com/196)

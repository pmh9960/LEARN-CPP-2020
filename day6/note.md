# Day 6

## Array

## String

- String is array of charactors.

- Two strings can be attached.

  - Single quote is charactor.

  - **Double quote is const char pointer, not string, not char pointer.**

  ```cpp
  std::string name = "Minho" + " hello!"; // const char* can't be added each other
  ```

  ```cpp
  std::string name = std::string("Minho") + " hello!"; // string can
  ```

- String has some methods.

```cpp
bool isThereHo = name.find("ho") != std::string::npos;
```

- How to store multiple lines.

  1. Use `R"()"`

     ```cpp
     const char *multipleLine = R"(Line1
     Line2
     Line3)";
     ```

  1. Use `'\n'`

     ```cpp
     const char *multipleLine2 = "Line1\n"
                                 "Line2\n"
                                 "Lin23\n";
     ```

## cf. String Literals in C++

- You did not only modify the contents declared `const char*`, but also `char*`.

  ```cpp
  const char *name = "Minho";
  name[2] = 'a'; // Illegal for all compilers
  char *name2 = "Minho";
  name2[2] = 'a'; // Illegal for some compilers
  ```

  If you want modify, USE ARRAY.

  ```cpp
  char name[] = "Minho";
  name[2] = "a";
  ```

- There are some friends with `const char*` in C++

  ```cpp
  const wchar_t*
  const char16_t*
  const char32_t*
  ...
  ```

  However, I do not interest in char or string a lot.

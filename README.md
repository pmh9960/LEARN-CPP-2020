# LEARN-CPP-2020

Learning C++

## Day 1

- Learn I/O, iostream.

## Day 2

- Solve some problems in [BAEKJOON](https://www.acmicpc.net/) with C++.

## Day 3

- Learn a concept of class and object oriented programming.

- Study from [The Charno](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb), Youtube channel.

## Day 4

- Learn about an enum and apply the enum in the previous log_level.cpp file.

- Constructor / Destructor

- Linked list with class

## Day 5

- Basic concept of Inheritance

- Virtual function and override

  - Pure virtual function

- Visibility

  - Private, protected, public

    1. Private : Only current class can see the members.

    1. Protected : Current class and its subclasses can see the members.

    1. public : Everyone can see the members.

  * new / delete

    ```cpp
    int *ptr = new int[5];
    delete[] ptr;
    ```

    1. `new` allocate the data to the heap memory (general = stack).

    1. The data in heap does not end when they go out of namespace (`{ }`).

    1. We have to use `delete` or `delete[]` to clean up the memory.

## [Day 6](day6/README.md)

- [Array](day6/array.cpp)

- [String](day6/string.cpp)

- cf. String Literals in C++

## [Day 7](day7/README.md)

- [Constant keyward (`const`)](day7/const.cpp)

- [Const in Class](day7/const_in_class.cpp)

- [Mutable keyword (`mutable`)](day7/mutable.cpp)

- [Member initializer list](day7/initializer_list.cpp)

- [Ternary operation](day7/ternary_operation.cpp)

- cf. How to declare multiple pointers in one-line.

- cf. Lambda

## [Day 8](day8/README.md)

- [Create/Instantiate objects](day8/instantiate_objects.cpp)

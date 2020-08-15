#include <iostream>

int main()
{
    // int array[10] = {'a', 'r', 'r', 'a', 'y'};
    char array[10] = {'a', 'r', 'r', 'a', 'y'};
    std::cout << array << std::endl;
    std::cout << int(array[4]) << std::endl; // 121 (ASCII)
    std::cout << int(array[5]) << std::endl; // NULL ?
    std::cout << sizeof(array) << std::endl;

    // String = Array of charactors
    const char *name = "Minho"; // Fixed allocate local memory
    // name[2] = 'e'; // Can't change
    std::cout << name << std::endl;
    std::cout << int(name[5]) << std::endl;
}
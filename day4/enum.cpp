#include <iostream>

enum Example : unsigned char // Declare type
{
    A = 3, // start value
    B,     // + 1
    C,     // + 2
    Hello = 10,
    Mino
};
// Enum start with 0, if you did not initialize. Then add 1 in every single variable.
// However, you can initialize any int, or char.
// If you declare a variable as Enum (in this case, Example), the variable only can get one of the enum.

int main()
{
    Example value = B;
    // Example value = 12; // error: invalid conversion from 'int' to 'Example'
    std::cout << "The value is " << value << std::endl;

    return 0;
}
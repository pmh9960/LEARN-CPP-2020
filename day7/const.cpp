#include <iostream>

int main()
{
    const int MAX_AGE = 90;

    int *a = new int;
    *a = 2;
    a = (int *)&MAX_AGE;
    std::cout << *a << std::endl;

    const int *b = new int;
    // *b = 2; // error
    b = (int *)&MAX_AGE;
    std::cout << *b << std::endl;

    int *const c = new int;
    *c = 2;
    // c = (int *)&MAX_AGE; // error
    std::cout << *c << std::endl;

    return 0;
}
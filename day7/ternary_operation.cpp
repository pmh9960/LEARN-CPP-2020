#include <iostream>
#include <string>

static int s_Level = 9;
static int s_Speed;

int main()
{
    // Normal ternary operation
    s_Speed = s_Level > 10 ? 20 : 10;
    std::cout << s_Speed << std::endl;

    // Nested ternary operation
    s_Speed = s_Level > 10 ? s_Level > 5 ? 30 : 20 : 10;
    std::cout << s_Speed << std::endl;

    return 0;
}
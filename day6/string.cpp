#include <iostream>
#include <string>

// void PrintString(std::string string) // Copy string => Too slow!
// void PrintString(const std::string string) // Use reference
void PrintString(const std::string &string) // Use reference and const
{
    // string += " copy"; // You do not modify (Recommend)
    std::cout << string << std::endl;
}

int main()
{
    std::string name = "Minho"; // + " hello!";
    name += " hello!";
    // PrintString(name);
    name.size();
    bool isThereHo = name.find("ho") != std::string::npos;
    std::cout << isThereHo << std::endl;
    std::cout << name << std::endl;

    char litheralName[] = "Minho";
    litheralName[2] = 'm';
    std::cout << litheralName << std::endl;

    const char *multipleLine = R"(Line1
Line2
Line3)";
    std::cout << multipleLine << std::endl;
    const char *multipleLine2 = "Line1\n"
                                "Line2\n"
                                "Lin23\n";
    std::cout << multipleLine2 << std::endl;

    return 0;
}
#include <iostream>
#include <string.h>

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
    String(const String &other)
    {
        // memcpy(this, &other, sizeof(String)); // This is what consturctor does, when there is no copy constructor.

        std::cout << "Copied String!" << std::endl;
        m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size);
        m_Buffer[m_Size] = 0;
    }
    // String(const String &other) = delete; // Looks like unique pointer.

    ~String()
    {
        delete m_Buffer;
    }

    char &operator[](unsigned int index) // operator which I already learned at day9
    {
        return m_Buffer[index];
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &string); // now this function can approach the private members
};

std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintCopiedString(String string) // copy string when the function takes it to argument
{
    std::cout << string << std::endl;
}

void PrintString(const String &string)
{
    std::cout << string << std::endl;
}

int main()
{
    String string("Minho");
    String second = string;
    second[2] = 'm';

    PrintCopiedString(string);
    PrintCopiedString(second);
}
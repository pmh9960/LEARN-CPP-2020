// // Function Version
// #include <iostream>

// void plus1()
// {
//     static int i = 0;
//     i++;
//     std::cout << i << std::endl;
// }

// int main()
// {
//     plus1();
//     plus1();
//     plus1();
//     plus1();
//     plus1();
// }

// // Class Version 1
// #include <iostream>
// class Singleton
// {
// private:
//     static Singleton *s_Instance;

// public:
//     static Singleton &Get()
//     {
//         return *s_Instance;
//     }
//     void Hello()
//     {
//     }
// };

// Singleton *Singleton::s_Instance = nullptr;

// int main()
// {
//     Singleton s;
//     s.Get().Hello();
// return 0;
// }

// Class Version 2
#include <iostream>
#include <typeinfo>

class Singleton
{
private:
    int s_Num = 0;

public:
    static Singleton &Get()
    {
        static Singleton *instance;
        return *instance;
    }
    void Set(int num)
    {
        s_Num = num;
    }
    void Show()
    {
        std::cout << s_Num << std::endl;
    }
    void Hello()
    {
    }
};

int main()
{
    Singleton s;
    s.Show();
    s.Set(3);
    s.Show();
    s.Get().Set(2);
    s.Get().Show();

    return 0;
}
#include <iostream>

// Linked list is made easier if I make it with structure, or I define l_Next as public.

class LinkedList
{
private:
    LinkedList *l_Next;
    int l_value;

public:
    LinkedList()
    {
        l_Next = nullptr;
        l_value = 0;
    }

    LinkedList *FindNext()
    {
        return l_Next;
    }
    void SetValue(int value)
    {
        l_value = value;
    }
    void Print()
    {
        std::cout << l_value << std::endl;
    }
    void MakeNext()
    {
        static LinkedList next;
        l_Next = &next;
    }
};

int main()
{
    LinkedList list;

    list.SetValue(10);
    list.Print();
    list.MakeNext();
    list.FindNext()->SetValue(2);
    list.FindNext()->Print();

    // Destruct
    list.FindNext()->~LinkedList();
    list.FindNext()->Print();
    list.~LinkedList();
    list.Print();
    // Why anything doesn't change ?

    return 0;
}
#include "list.hpp"

int main()
{
    LinkedList <int> list;

    for (int i = 0; i < 10; ++i)
    {
        list.PushBack(i);
    }
    list.Traverse();

    std::cout << "Reverse list:\n";
    list.Reverse();
    list.Traverse();

    std::cout << "Pop back and front:\n";
    list.PopBack();
    list.PopFront();
    list.Traverse();

    std::cout << "Push back and front:\n";
    list.PushBack(10);
    list.PushFront(25);
    list.Traverse();

    std::cout << "Reverse list:\n";
    list.Reverse();
    list.Traverse();

    return 0;
}
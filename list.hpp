#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T> class LinkedList;

 //Класс узла списка
template <typename T>
class Node
{
     friend class LinkedList<T>;
public:
    Node():
        data(0),
        next(nullptr)
    {
    }

    Node(T _data) :
        data(_data),
        next(nullptr)
    {
    }

private:
    T data;
    Node <T>* next;
};

// Класс списка
template <typename T>
class LinkedList
{

public:
    LinkedList() :
        head(nullptr),
        tail(nullptr)
    {
    }


    void PushBack(T _data);
    void PushFront(T _data);

    void PopBack();
    void PopFront();

    void Traverse();

    // Метод разворачивающий список
    void Reverse();

private:
    Node <T>* head;
    Node <T>* tail;
};

template <typename T>
void LinkedList<T>::PushBack(T _data)
{
    Node <T>* newNode = new Node<T>(_data);

    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::Traverse()
{
    Node <T>* current = head;

    if (head == nullptr)
    {
        std::cout << "Empty..." << std::endl;
        return;
    }

    while (current != nullptr)
    {
        std::cout<<current->data<<" -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

template <typename T>
void LinkedList<T>::Reverse()
{
    Node <T>* tempHead = head;
    Node <T>* restNode = nullptr;
    Node <T>* nextNode = nullptr;

    if (head == nullptr)
        return;

    tail = head;
    restNode = head->next;

    while (restNode != nullptr)
    {
        nextNode = restNode;
        restNode = restNode->next;
        nextNode->next = tempHead;
        tempHead = nextNode;
    }

    head = tempHead;
    tail->next = nullptr;
}

template <typename T>
void LinkedList<T>::PopBack()
{
    if (tail == nullptr)
        return;
    else
    {
        Node <T>* removeNode;
        removeNode = tail;
        if (head == tail)
            head = tail = nullptr;
        else
        {
            Node <T>* prevTail = head;
            while (prevTail->next != tail)
                prevTail = prevTail->next;

            tail = prevTail;
            tail->next = nullptr;
        }
        delete removeNode;
    }
}

template <typename T>
void LinkedList<T>::PopFront(){
    if (head == nullptr)
        return;
    else
    {
        Node <T>* removeNode;
        removeNode = head;

        if (head == tail)
            head = tail = nullptr;
        else
            head = head->next;
        delete removeNode;
    }
}

template <typename T>
void LinkedList<T>::PushFront(T _data)
{
    Node <T>* newNode = new Node<T>(_data);

    if (head == nullptr)
    {
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

#endif //LIST_HPP

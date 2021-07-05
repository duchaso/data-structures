#ifndef LIST_H
#define LIST_H
#include <iostream>
struct Node
{
    int el;
    Node* next;

    Node(){};
    Node(int el)
    : el(el), next(nullptr)
    {};
};

class List
{
public:
    List();
    virtual ~List();

public:
    void push_b(int el)
    {
        if(head == nullptr)
        {
            head = new Node(el);
            tail = head;
        }
        else
        {
            Node* node = new Node(el);
            tail->next = node;
            tail = node;
        }
    }
    void ins(int el, Node* current)
    {
    Node* node = new Node(el);
        node->next = current->next;
        current->next = node;
    }

    void pop(Node* current)
    {
        if(current->next == tail)
        {
            delete current->next;
            current->next = nullptr;
        }
        else
        {
            Node* buf = current->next;
            current->next = current->next->next;
            delete buf;
        }
    }

    void print()
    {
        auto current = head;
        do
        {
            std::cout << current->el << std::endl;
            current = current->next;
        } while(current != tail);
        std::cout << current->el << std::endl;
    }

private:
    Node* tail = nullptr;
public:
    Node* head = nullptr;
};


#endif // LIST_H

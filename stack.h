#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

typedef char datatype;

struct link
{
    datatype data;
    link *next;
};

class Stack
{
public:
        link *first;
        Stack() : first(nullptr) {}
        ~Stack();
        void Push(datatype value);
        void Pop();
        void Show();
};

void Stack::Push(datatype value)
{
    link *newlink = new link;
    newlink->data = value;
    newlink->next = first;
    first = newlink;
}

void Stack::Pop()
{
    if (first)
    {
        link *temp = first;
        first = temp->next;
        delete temp;
    }
    else
    {
        cout << "Стек порожній!" << endl;
        exit(0);
    }
}

void Stack::Show()
{
    cout << "Вміст стеку: " << endl;
    link *current = first;
    if (!current) cout << "Стек порожній!" << endl;
    while(current)
    {
        cout << "|| " << current->data << " ||" << endl;
        current = current->next;
    }
}

Stack::~Stack()
{
    while(first)
    {
        link *temp = first->next;
        delete first;
        first = temp;
    }
}


#endif // STACK_H

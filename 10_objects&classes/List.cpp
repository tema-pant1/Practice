#include "List.h"
#include <iostream>

namespace LIST
{
    Node::Node(Item dt, Node* nxt)
    {
        next = nxt;
        data = dt;
    }

    Node::~Node()
    {
        if (next != nullptr)
            delete next;
    }

    List::List()
    {
        head = tail = nullptr;
        size = 0;
    }

    List::~List()
    {
            delete head;
    }

    void List::push_back(const Item& elem)
    {
        if (is_full()) 
        {
            std::cout << "Warning! List is full, max " << LIMIT << " elements.\n";
            return;
        }
        if (is_empty())
        {
            Node* nd = new Node(elem);
            head = tail = nd;
            size++;
        }
        else
        {
            Node* nd = new Node(elem);
            tail->next = nd;
            tail = nd;  
            size++;
        }
    }

    void List::visit(void (*pf)(Item& itm))
    {
        Node* cur = head;
        while(cur)
        {
            pf(cur->data);
            cur = cur->next;
        }
    }
}
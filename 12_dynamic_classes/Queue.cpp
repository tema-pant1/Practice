#include "Queue.h"
#include <random>

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node* temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::enqueue(const Item& item)
{
    if (is_full())
        return 0;
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return 1;
}

bool Queue::dequeue(Item& item)
{
    if (front == nullptr)
        return 0;
    item = front->item;
    items--;
    Node* temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return 1;
}

void customer::set(long when)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 3);
    process_time = dist(gen);
    arrive = when;
}
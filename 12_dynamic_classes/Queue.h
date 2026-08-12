#pragma once

class customer {
private:
    long arrive;
    int process_time;

public:
    customer() {arrive = process_time = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return process_time;}
};

typedef customer Item;

class Queue {
private:
    struct Node {
        Item item;
        Node* next;
    };
    static const int Q_SIZE = 10;
    Node* front;
    Node* rear;
    int items;
    const int qsize;

    Queue(const Queue& q) : qsize(0) {}
    Queue& operator=(const Queue& c) {return *this;}

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool is_empty() const {return items == 0;}
    bool is_full() const {return items == qsize;}
    int queue_count() const {return items;}
    bool enqueue(const Item& item);
    bool dequeue(Item& item);
};
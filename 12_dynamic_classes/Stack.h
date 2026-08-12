#pragma once

typedef unsigned long Item;

class Stack {
private:
    static const int MAX = 10;
    Item* pitems;
    int size;
    int top;

public:
    Stack(int n = 10);
    Stack(const Stack& st);
    ~Stack();
    
    bool isfull() const {return top == size;}
    bool isempty() const {return top == 0;}
    bool push(const Item& item);
    bool pop (Item& item);

    Stack& operator=(const Stack& st);
};
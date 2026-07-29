#pragma once

struct customer {
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack {

private:
    static const int MAX = 10;
    Item items[MAX];
    int top;

public:
    
    Stack();
    bool is_empty() const;
    bool is_full() const;
    bool push(const Item& item);
    bool pop(Item& item);    
};
#pragma once

typedef int Item;

namespace LIST
{   
    struct Node {
            Item data;
            Node* next;
            Node(Item dt = 0, Node* nxt = nullptr);
            ~Node();    
    };

    class List {
        private:
            Node* head;
            Node* tail;
            int size;
            static const int LIMIT = 10;

        public:
            List();
            ~List();
            void push_back(const Item& elem);
            bool is_empty() const {return size == 0;};
            bool is_full() const {return size == LIMIT;};
            void visit(void (*pf)(Item&));
    };
}
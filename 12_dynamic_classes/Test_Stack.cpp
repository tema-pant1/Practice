#include "Stack.h"
#include <iostream>

using namespace std;

void fill_stack(Stack& st, Item (*pf)(Item))
{
    Item i = 0;
    while(st.push(pf(i)))
        i++;
}

Item sum(Item item)
{
    return item+item;
}

Item sqr(Item item)
{
    return item*item;
}

void show(Stack& st)
{
    Item temp;
    while(!st.isempty())
    {
        st.pop(temp);
        cout << temp << endl;
    }
}

int main()
{
    Stack s1, s2(5), s3(s2);
    fill_stack(s1, sum);
    fill_stack(s2, sqr);
    s3 = s1;
    cout << "Stack s1:\n";
    show(s1);
    cout << "Stack s2:\n";
    show(s2);
    cout << "Stack s3:\n";
    show(s3);
    
}
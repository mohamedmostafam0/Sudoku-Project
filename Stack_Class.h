#ifndef STACK
#define STACK


#include <iostream>
using namespace std;
typedef char StackElement;
const int DEFAULT_CAPACITY = 81;

class Stack
{

public:
    Stack();
    ~Stack();
    bool empty() const;
    void push(const StackElement &value);
    void display(ostream &out) const;
    StackElement top() const;
    void pop();

private:
    class Node
    {
    public:
        StackElement data;
        Node *next;
        Node(StackElement value, Node *link = 0) : data(value), next(link) {}
    };
    typedef Node *NodePointer;
    NodePointer myTop; 
};

ostream &operator<<(ostream &out, const Stack &aStack);

#endif /* STACK */

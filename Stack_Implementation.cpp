#include "Stack_Class.h"

Stack::Stack() : myTop(NULL) {}

Stack::~Stack()
{
    Stack::NodePointer currPtr = myTop, nextPtr = NULL;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

bool Stack::empty() const
{
    return myTop == NULL;
}

void Stack::push(const StackElement &value)
{
    myTop = new Stack::Node(value, myTop);
}

void Stack::display(ostream &out) const
{
    if (empty())
    {
        cerr << "Stack-empty!" << endl;
        return;
    }
    Stack::NodePointer myPtr = myTop;
    while (myPtr != NULL)
    {
        out << myPtr->data << ' ';
        myPtr = myPtr->next;
    }
    out << endl;
}

StackElement Stack::top() const
{
    if (!empty())
        return myTop->data;
    else
    {
        cerr << "Stack Empty -- Returning garbage." << endl;
        StackElement garbage;
        return garbage;
    }
}

void Stack::pop()
{
    if (!empty())
    {
        Stack::NodePointer ptr = myTop;
        myTop = myTop->next;
        delete ptr;
    }
    else
    {
        cerr << "Stack Empty!" << endl;
    }
}

ostream &operator<<(ostream &out, const Stack &aStack)
{
    aStack.display(out);
    return out;
}

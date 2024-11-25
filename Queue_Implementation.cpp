#include "Queue_Class.h"

Queue::Queue() : myFront(NULL), myBack(NULL) {}

Queue::~Queue()
{
    Queue::NodePointer currPtr = myFront, nextPtr = NULL;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

bool Queue::empty() const
{
    return myFront == NULL;
}

void Queue::enqueue(const QueueElement &value)
{
    Queue::NodePointer newptr = new Queue::Node(value);
    if (empty())
    {
        myFront = myBack = newptr;
    }
    else
    {
        myBack->next = newptr;
        myBack = newptr;
    }
}

void Queue::display(ostream &out) const
{
    if (empty())
    {
        cerr << "Queue-empty!" << endl;
        return;
    }
    Queue::NodePointer myPtr = myFront;
    int countcol = 0;
    int countrow = 1;
    while (myPtr != NULL)
    {
        while (countcol != 9)
        {
            if (countcol == 0)
            {
                out << "    ";
            }
            out << countcol + 1 << " ";
            countcol++;
            if (countcol == 9)
            {
                out << endl;
                out << "  * * * * * * * * * *";
            }
        }
        out << endl;
        out << countrow << " * ";
        for (int j = 0; j < 9; j++)
        {
            out << myPtr->data << ' ';
            myPtr = myPtr->next;
        }
        countrow++;
    }
    cout << endl;
}

QueueElement Queue::front() const
{
    if (!empty())
        return myFront->data;
    else
    {
        cerr << "Queue Empty -- Returning garbage." << endl;
        QueueElement garbage;
        return garbage;
    }
}

void Queue::dequeue()
{
    if (!empty())
    {
        Queue::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
        if (myFront == NULL) // queue is now empty
            myBack = NULL;
    }
    else
    {
        cerr << "Queue Empty!" << endl;
    }
}

void Queue::undodequeue(QueueElement data)
{
    NodePointer dataPtr = new Node(data);
    dataPtr->next = myFront;
    myFront = dataPtr;
}

bool Queue::returnvalue()
{
    Queue::NodePointer ptr = myFront;
    while (ptr != NULL)
    {
        if (ptr->data == '-')
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

QueueElement Queue::traverse(int pos)
{
    Queue::NodePointer ptr = myFront;
    for (int i = 0; i < pos; i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

ostream &operator<<(ostream &out, const Queue &aQueue)
{
    aQueue.display(out);
    return out;
}

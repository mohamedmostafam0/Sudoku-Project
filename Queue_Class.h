#ifndef QUEUE
#define QUEUE

#include <iostream>
using namespace std;
typedef char QueueElement;

class Queue
{

public:
    Queue();
    ~Queue();
    // const Queue &operator=(const Queue &rhs);
    bool empty() const;
    void enqueue(const QueueElement &value);
    void display(ostream &out) const;
    QueueElement front() const;
    void undodequeue(char data);
    QueueElement traverse(int pos);
    void dequeue();
    bool returnvalue(/*QueueElement &data*/);

private:
    class Node
    {
    public:
        QueueElement data;
        Node *next;
        Node(QueueElement value, Node *link = 0) : data(value), next(link) {}
    };
    typedef Node *NodePointer;
    NodePointer myFront, myBack;
};

ostream &operator<<(ostream &out, const Queue &aList);

#endif /* QUEUE */

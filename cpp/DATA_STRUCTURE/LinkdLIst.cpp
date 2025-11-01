#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *ptr = NULL;
};

class SLL
{
private:
    Node *head;

public:
    SLL();
    void insertFirst(int);
    void insertLast(int);
};

SLL::SLL()
{
    head = NULL;
}

void SLL::insertFirst(int data)
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cerr << "Memory allocation failed" << endl;
    }
    newNode->data = data;
    newNode->ptr = head;
    head = newNode;
}

void SLL::insertLast(int data)
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cerr << "Memory allocation failed" << endl;
    }
    newNode->data = data;
    newNode->ptr = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->ptr != nullptr)
    {
        temp = temp->ptr;
    }
    temp->ptr = newNode;
}

int main()
{
    SLL list = SLL();
    return 0;
}
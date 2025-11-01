#include <iostream>
using namespace std;
#define OVERFLOW 1
#define INVALID_INDEX 2
class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int);
    Array(Array &);
    Array &operator=(Array &);
    bool isEmpty();
    bool isFull();
    void appEnd(int);
    void insertAtPosition(int, int);
    void edit(int, int);
    int del(int);
    int getValue(int);
    int countElement();
    int find(int);
    ~Array();
};

Array::Array(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

bool Array::isEmpty()
{
    return lastIndex == -1;
}

void Array::appEnd(int data)
{
    if (isFull())
    {
        throw OVERFLOW;
    }
    ptr[lastIndex + 1] = data;
    lastIndex++;
}

bool Array::isFull()
{
    return lastIndex == capacity - 1;
}

void Array::insertAtPosition(int index, int data)
{
    if (index < 0 || index > lastIndex)
    {
        throw INVALID_INDEX;
    }
    if (isFull())
    {
        throw OVERFLOW;
    }
    for (int i = lastIndex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[index] = data;
    lastIndex++;
}

void Array::edit(int index, int data)
{
    if (index < 0 || index > lastIndex)
    {
        throw INVALID_INDEX;
    }
    ptr[index] = data;
}

int Array::del(int index)
{
    if (index < 0 || index > lastIndex)
    {
        throw INVALID_INDEX;
    }
    for (int i = index; i < lastIndex; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastIndex--;
}

int Array::getValue(int index)
{
    if (index < 0 || index > lastIndex)
    {
        throw INVALID_INDEX;
    }
    return ptr[index];
}

int Array::countElement()
{
    return lastIndex + 1;
}

Array::~Array()
{
    delete[] ptr;
}

int Array::find(int data)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

Array::Array(Array &arr)
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}

Array &Array::operator=(Array &arr)
{
    if (ptr != nullptr)
    {
        delete[] ptr;
    }
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
    return *this;
}

int main()
{
    Array arr(4);

    return 0;
}
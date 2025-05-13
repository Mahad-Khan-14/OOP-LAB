#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
    T *arr;
    int front, rear, capacity, size;

public:
    Queue(int cap) : capacity(cap), size(0), front(0), rear(-1)
    {
        arr = new T[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(T value)
    {
        if (size == capacity)
            throw QueueOverflowException();

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        ++size;
    }

    T dequeue()
    {
        if (size == 0)
            throw QueueUnderflowException();

        T val = arr[front];
        front = (front + 1) % capacity;
        --size;
        return val;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }
};

int main()
{
    Queue<int> q(3);

    try
    {
        cout << "Attempting to enqueue to a full queue...\n";
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    }
    catch (const QueueOverflowException &e)
    {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try
    {
        cout << "\nAttempting to dequeue from an empty queue...\n";
        Queue<int> q2(2);
        q2.dequeue();
    }
    catch (const QueueUnderflowException &e)
    {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}

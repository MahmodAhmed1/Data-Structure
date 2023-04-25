#include <iostream>

using namespace std;

template <class T>
class queue
{
    T *arr;       // array to store the queue elements
    int capacity; // maximum size of the queue
    int size;     // current size of the queue
    int front;    // index of first element in queue
    int back;     // index of last element in queue
public:
    queue() // default constructor that takes the initial size of the queue
    {
        arr = new T[100];
        size = 0;
        capacity = 100;
        front = -1;
        back = -1;
    }
    queue(int S) // parameterised constructor that takes the initial size of the queue
    {
        arr = new T[S];
        size = 0;
        capacity = S;
        front = -1;
        back = -1;
    }
    void enqueue(T element) // insert element at end of queue
    {
        if (size < capacity)
        {
            if (front == -1)
            {
                front++;
            }
            back++;
            arr[back] = element;
            size++;
        }
    }
    void dequeue() // remove element from the front of the queue
    {
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            back--;
            size--;
        }
    }
    int Size() // return the size of queue
    {
        return size;
    }
    T Front() // return first element in queue
    {
        return arr[front];
    }
    T Back() // return last element in queue
    {
        return arr[back];
    }
    int qcapacity()
    {
        return capacity;
    }
    bool empty() // return true if queue is empty
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void clear()
    {
        while (size > 0)
        {
            dequeue();
        }
        front = -1;
        back = -1;
    }
    void print()
    {
        cout << "size = " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
    ~queue()
    {
        delete[] arr;
    }
};

class stack
{
    queue<int> q1; // stack only has 1 member variable which is the underlying queue
public:
    stack() // this constructor calls stack with a default queue of capacity 100
    {
    }
    void push(int value) // calls the enqueue function of the queue
    {
        q1.enqueue(value);
    }
    int top() // returns last element in the queue
    {
        return q1.Back();
    }
    void pop() // makes a new queue without the last element 
    {
        queue<int> Q(q1.qcapacity()); // temporary queue
        while (q1.Size() > 1)
        {
            Q.enqueue(q1.Front());
            q1.dequeue();
        }
        q1.clear();
        while (Q.Size() > 0)
        {
            q1.enqueue(Q.Front());
            Q.dequeue();
        }
    }
    void print()
    {
        q1.print();
    }
};

int main()
{
    stack s1;
    s1.push(2);
    s1.push(4);
    s1.push(3);
    s1.print();
    s1.pop();
    s1.print();
    s1.pop();
    s1.push(5);
    s1.push(6);
    s1.print();
    return 0;
}
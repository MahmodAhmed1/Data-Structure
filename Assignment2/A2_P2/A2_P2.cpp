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
        else
        {
            cout << "Overflow!" << endl;
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
        else
        {
            cout << "Underflow!" << endl;
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
    /*T Back() // return last element in queue
    {
        return arr[back];
    }*/
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
            this->dequeue();
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

// buyTicket reduces all the tickets needed to be bought by people in line by 1 and increases time taken respectfully
void buyTicket(queue<int> &q, int &t, int &k)
{
    // tickets will store the tickets of the currently first person in queue
    int tickets;
    // s will store the size of the queue since it will be changed in the loop
    int s = q.Size();
    for (int i = 0; i < s; i++)
    {
        if (q.Front() == 1)
        {
            q.dequeue();
            t++;
            // adding exception when the index of person is first in line for accurate calculations
            if (k > 0 && k >= i)
            {
                k--;
            }
        }
        else
        {
            tickets = q.Front() - 1;
            q.enqueue(tickets);
            q.dequeue();
            t++;
        }
    }
}
void testcase1()
{
    cout << "input: tickets = [2, 1, 3, 1, 2], k = 2" << endl;
    int num, time, k, condition;
    k = 2;
    time = 0;
    num = 5;
    int tickets[num] = {2, 1, 3, 1, 2};
    condition = tickets[k];
    queue<int> line1(100);
    for (int i = 0; i < num; i++)
    {
        line1.enqueue(tickets[i]);
    }
    while (condition > 1)
    {
        buyTicket(line1, time, k);
        condition--;
    }
    time += (1 + k);
    cout << "time taken: " << time << endl;
}
void testcase2()
{
    cout << "input: tickets = [10, 10, 10], k = 1" << endl;
    int num, time, k, condition;
    k = 1;
    time = 0;
    num = 3;
    int tickets[num] = {10, 10, 10};
    condition = tickets[k];
    queue<int> line2(100);
    for (int i = 0; i < num; i++)
    {
        line2.enqueue(tickets[i]);
    }
    while (condition > 1)
    {
        buyTicket(line2, time, k);
        condition--;
    }
    time += (1 + k);
    cout << "time taken: " << time << endl;
}
void testcase3()
{
    cout << "input: tickets = [3, 8], k = 1" << endl;
    int num, time, k, condition;
    k = 1;
    time = 0;
    num = 2;
    int tickets[num] = {3, 8};
    condition = tickets[k];
    queue<int> line2(100);
    for (int i = 0; i < num; i++)
    {
        line2.enqueue(tickets[i]);
    }
    while (condition > 1)
    {
        buyTicket(line2, time, k);
        condition--;
    }
    time += (1 + k);
    cout << "time taken: " << time << endl;
}
void testcase4()
{
    cout << "input: tickets = [7, 2, 4, 5, 10], k = 4" << endl;
    int num, time, k, condition;
    k = 4;
    time = 0;
    num = 5;
    int tickets[num] = {7, 2, 4, 5, 10};
    condition = tickets[k];
    queue<int> line1(100);
    for (int i = 0; i < num; i++)
    {
        line1.enqueue(tickets[i]);
    }
    while (condition > 1)
    {
        buyTicket(line1, time, k);
        condition--;
    }
    time += (1 + k);
    cout << "time taken: " << time << endl;
}
void testcase5()
{
    int num, time, k, condition;
    time = 0;
    // taking the initial queue size as input
    cout << "Enter number of people in line: ";
    cin >> num;
    int tickets[100];
    // initialising the max queue size to 100
    queue<int> line(100);
    cout << "Tickets: ";
    // looping to input initial queue values
    for (int i = 0; i < num; i++)
    {
        cin >> tickets[i];
        line.enqueue(tickets[i]);
    }
    cout << "Enter value of k: ";
    cin >> k;
    // k is the index of the person we are calculating time for
    // while condition is the number of tickets this person needs to buy
    condition = tickets[k];
    // looping and subtracting the queue by 1 till the person needs only one ticket
    while (condition > 1)
    {
        buyTicket(line, time, k);
        condition--;
    }
    // when person needs 1 ticket, adding current time by the index of the person in the current queue
    time += (1 + k);
    cout << "time taken: " << time;
}

int main()
{
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();
    return 0;
}
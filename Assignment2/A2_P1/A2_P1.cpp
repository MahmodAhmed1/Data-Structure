#include <iostream>
#include <string>

using namespace std;

template <class T>
class stack
{
    T *arr;
    int top;      // top index
    int size;     // size of stack
    int capacity; // maximum size of stack
public:
    // Paramatrized constructor that takes maximum capacity
    stack(int cap)
    {
        arr = new T[cap];
        capacity = cap;
        size = 0;
        top = -1;
    }
    // Default constructor
    stack()
    {
        arr = new T[100];
        capacity = 100;
        size = 0;
        top = -1;
    }
    // Add element to the top of the stack
    void Push(T element)
    {
        if (size < capacity)
        {
            top++;
            arr[top] = element;
            size++;
        }
    }
    // Remove an element from top of the stack
    void Pop()
    {
        top--;
        size--;
    }
    // Get the element at the top of the stack
    T Top()
    {
        return arr[top];
    }
    // Return the size of the stack
    int Size()
    {
        return size;
    }
};

void Convert(string path, stack<char> &s)
{
    // Variable to store the size of the string
    int size = path.length();
    // Condition that Removes the last element if its a forward slash
    if (path[size - 1] == '/')
    {
        size--;
    }
    for (int i = size - 1; i >= 0; i--)
    {

        // Condition to remove any period and replace it with a forward slash
        if (path[i] == '.')
        {
            path[i] = '/';
        }
        // if it finds any 2 consecutive forward slashes... continue
        if (path[i] == '/' && path[i + 1] == '/')
        {
            continue;
        }
        s.Push(path[i]);
    }
}

void print(stack<char> &s)
{
    int size = s.Size();
    cout << "Output:\"";
    for (int i = 0; i < size - 1; i++)
    {
        cout << s.Top();
        s.Pop();
    }
    // if last element is still a forward slash pop it
    if (s.Top() == '/')
    {
        s.Pop();
    }
    if (s.Size()>0)
    {
        cout << s.Top();
        s.Pop();
    }
    
    cout << "\"" << endl;
}

void test_case1()
{
    stack<char> s1;
    string path;
    cout << "Input: path =\"/a//b//c//////d\"" << endl;
    path = "/a//b//c//////d";
    Convert(path, s1);
    print(s1);
}

void test_case2()
{
    stack<char> s1;
    string path;
    cout << "Input: path =\"/a/../.././../../.\"" << endl;
    path = "/a/../.././../../.";
    Convert(path, s1);
    print(s1);
}

void test_case3()
{
    stack<char> s1;
    string path;
    cout << "Input: path =\"/a/./b/./c/./d/\"" << endl;
    path = "/a/./b/./c/./d/";
    Convert(path, s1);
    print(s1);
}

void test_case4()
{
    stack<char> s1;
    string path;
    cout << "input: path = ";
    cin >> path;
    Convert(path, s1);
    print(s1);
}

int main()
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    return 0;
}
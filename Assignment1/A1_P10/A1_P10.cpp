#include <iostream>

using namespace std;

template<class T>
class List {

private:
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node() {
            data = 0;
            next = prev = nullptr;
        }

        explicit Node(T value) : data(value) {
            next = prev = nullptr;
        }
    };

    Node *head;
    Node *tail;
    Node *dummyNode;
    int count;

    bool out_of_range(int index) {
        if (index < 0 || index > count) {
            std::cout << "Index out of bounds.\n";
            return true;
        }
        return false;
    }

    void init() {
        dummyNode = new Node;
        head = new Node;
        tail = new Node;
        count = 0;
    }

public:
    class iterator {
    public:
        iterator() : current{nullptr} {}

        const T &operator*() const {
            return retrieve();
        }

        iterator &operator++() {
            if (current == nullptr)
                throw "Out of range";
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            if (current == nullptr)
                throw "Out of range";
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator &operator--() {
            if (current == nullptr)
                throw "Out of range";

            current = current->prev;
            return *this;
        }

        iterator operator--(int) {
            if (current == nullptr)
                throw "Out of range";
            iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const iterator &other) const {
            return current == other.current;
        }

        bool operator!=(const iterator &other) const {
            return !(*this == other);
        }

    private:
        Node *current;

        iterator(Node *node) : current{node} {}

        T &retrieve() const {
            return current->data;
        }

        friend class List<T>;
    };

    List() {
        init();
    }

    List(T value, int initial_size) {
        init();
        for (int i = 0; i < initial_size; i++)
            push_back(value);
    }

    List(const List &other) {
        init();
        for (auto &value: other)
            push_back(value);
    }

    List &operator=(const List &other) {
        List copy = other;
        std::swap(*this, copy);
        return *this;
    }


    List(List &&other) : count{other.count}, head{other.head}, tail{other.tail} {
        other.count = 0;
        other.head = other.tail = nullptr;
    }

    List &operator=(List &&other) {
        std::swap(count, other.count);
        std::swap(head, other.head);
        std::swap(tail, other.tail);

        return *this;
    }

    int size() const {
        return count;
    }

    void push_front(T value) {
        Node *newNode = new Node(value);
        if (count == 0) {
            head = tail = newNode;
            tail->next = dummyNode;
            dummyNode->prev = tail;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++count;
    }

    void push_back(T value) {
        Node *newNode = new Node(value);
        if (count == 0) {
            head = tail = newNode;
            tail->next = dummyNode;
            dummyNode->prev = tail;
        } else {
            newNode->next = dummyNode;
            dummyNode->prev = newNode;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++count;
    }

    void pop_back() {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
            return;
        }
        Node *d = tail;
//        tail->prev->next = tail->next;
        tail = tail->prev;
        delete d;
        --count;
    }

    void pop_front() {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
            return;
        }
        Node *d = head;
        head = head->next;
        delete d;
        --count;
    }


    void insert(T value, iterator postion) {
        if (postion != end() && postion.current == nullptr)
            throw exit;
        if (postion.current == head)push_front(value);
        else if (postion.current == dummyNode)push_back(value);
        else {
            Node *newNode = new Node(value);
            Node *ptr = postion.current;
            ptr->prev->next = newNode;
            newNode->next = ptr;
            newNode->prev = ptr->prev;
            ptr->prev = newNode;
            ++count;
        }
    }

    void Indexinsert(int index, T value) {

        if (out_of_range(index))
            throw exit;

        Node *newNode = new Node(value);
        if (index == 0)
            push_front(value);

        else if (index == count - 1)
            push_back(value);

        else {
            Node *ptr = head;

            for (int i = 0; i < index - 1; ++i)
                ptr = ptr->next;

            ptr->next->prev = newNode;
            newNode->next = ptr->next;
            ptr->next = newNode;
            newNode->prev = ptr;
            ++count;
        }
    }


    void erase(iterator position) {
        if (isEmpty()) {
            std::cout << "List if empty.\n";
            return;
        }
        if (position != end() && position.current == nullptr) {
            throw exit;
        }

        if (position == head)
            pop_front();
        else if (position == tail)
            pop_back();
        else {
            Node *ptr = position.current;
            iterator retVal = ptr->next;
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
            --count;
        }
    }

    iterator begin() const {
        return head;
    }

    iterator end() const {
        return tail->next;
    }

    bool find(T value) {
        Node *ptr = head;
        while (ptr != tail) {
            if (ptr->data == value)
                return true;
            ptr = ptr->next;
        }
        return (tail->data == value);
    }

    bool isEmpty() const {
        return (count == 0);
    }

    void clear() {
        if (isEmpty()) {
            return;
        }
        while (!isEmpty())
            pop_back();
    }

    ~List() {
        clear();
        delete head;
        delete tail;
        delete dummyNode;
    }
};

int main() {
    cout << "default constructor\n";
    List<int> defList;
    defList.push_back(2);
    defList.push_front(1);
    for (auto x: defList)
        cout << x << ' ';
    cout << '\n';
    cout << "parameterized  constructor\n";
    List<int> parList(5, 3);
    for (auto x: parList)
        cout << x << ' ';
    cout << '\n';
    cout << "size: " << parList.size() << '\n';
    parList = defList;
    for (auto x: parList)
        cout << x << ' ';
    cout << '\n';
    cout << "using iterator after copy constructor\n";
    auto it = parList.end();
    it--;
    cout << *it << endl;
    cout << "insert in the the second postion\n";
    auto bit = parList.begin();
    bit++;
    parList.insert(3, bit);
    for (auto x: parList)
        cout << x << ' ';
    cout << '\n';
    cout << "delete in the the second postion\n";
    auto it2 = parList.begin();
    it2++;
    parList.erase(it2);
    for (auto x: parList)
        cout << x << ' ';

    return 0;
}
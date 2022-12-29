#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Dequeue {
public:
    class Node {
    public:
        Node *next, *prev;
        int value;

        Node(int val): value(val) {next = nullptr, prev = nullptr;}
    };
    Node *head, *tail;

    Dequeue() {
        head = nullptr, tail = nullptr;
    }

    void push_back(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node -> prev = tail;
            tail -> next = node;
            tail = node;
        }
    }

    void push_front(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node -> next = head;
            head -> prev = node;
            head = node;
        }
    }

    void pop_back() {
        assert(tail != nullptr);

        Node *node = tail;

        if (head == tail) {
            head = tail = nullptr;
        }

        else {
            node -> prev -> next = nullptr;
            tail = node -> prev;
        }

        free(node);
    }

    void pop_front() {
        assert(head != nullptr);

        Node *node = head;

        if (head == tail) {
            head = tail = nullptr;
        }

        else {
            node -> next -> prev = nullptr;
            head = node -> next;
        }

        free(node);
    }

    int back() const {
        assert(tail != nullptr);
        return tail -> value;
    }

    int front() const {
        assert(head != nullptr);
        return head -> value;
    }

    bool is_empty() const {
        return head == nullptr;
    }

    void print() const {
        Node *node = head;
        cout << "{";
        while (node) {
            cout << node -> value;
            cout << (node -> next ? ", ": "");
            node = node -> next;
        }
        cout << "}\n";
    }
};

int main() {
    Dequeue deque;

    deque.push_back(5);
    deque.push_back(10);
    deque.print();

    deque.push_back(0);
    deque.pop_front();
    deque.print();

    int val_front = deque.front();
    int val_back = deque.back();

    cout << "Front: " << val_front << ", back: " << val_back << '\n';

    deque.pop_back(); deque.pop_back();

    cout << "Dequeue is " << (deque.is_empty() ? "Empty" : "Not Empty") << '\n';

    return 0;
}
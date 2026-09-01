
#include <iostream>
using namespace std;

template <typename T>
class CircularList {
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* tail = nullptr;
    int sz = 0;

public:
    void push(T val) {
        Node* n = new Node(val);
        if (!tail) {
            tail = n;
            tail->next = tail;
        } else {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
        sz++;
    }

    void pop() {
        if (!tail) return;
        Node* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
        sz--;
    }

    void print() {
        if (!tail) return;
        Node* curr = tail->next;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << "\n";
    }

    int size() { return sz; }
};

int main() {
    CircularList<int> l;
    l.push(10);
    l.push(20);
    l.push(30);
    l.print();
    cout << "Розмір: " << l.size() << "\n";
    l.pop();
    l.print();
}












